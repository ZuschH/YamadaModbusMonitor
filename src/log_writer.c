#include "log_writer.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

static void format_timestamp(char* buffer, size_t size) {
    struct timespec ts;
    struct tm* tm_info;

    clock_gettime(CLOCK_REALTIME, &ts);
    tm_info = localtime(&ts.tv_sec);

    snprintf(buffer, size, "%04d-%02d-%02dT%02d:%02d:%02d.%03ld",
        tm_info->tm_year + 1900, tm_info->tm_mon + 1, tm_info->tm_mday,
        tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec, ts.tv_nsec / 1000000);
}

void log_csv_frame(FILE* file, const char* direction,
                   int slave_id, int function_code,
                   const uint8_t* data, int data_len,
                   int crc_ok, int response_time_ms) {

    char timestamp[64];
    format_timestamp(timestamp, sizeof(timestamp));

    fprintf(file, "%s,%s,%d,0x%02X,\"", timestamp, direction, slave_id, function_code);
    for (int i = 0; i < data_len; ++i) {
        fprintf(file, "%02X", data[i]);
        if (i < data_len - 1) fprintf(file, " ");
    }
    fprintf(file, "\",%d,", crc_ok);

    if (strcmp(direction, "RX") == 0)
        fprintf(file, "%d", response_time_ms);

    fprintf(file, "\n");
    fflush(file);
}
