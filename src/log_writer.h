#ifndef LOG_WRITER_H
#define LOG_WRITER_H

#include <stdint.h>
#include <stdio.h>

void log_csv_frame(FILE* file, const char* direction,
                   int slave_id, int function_code,
                   const uint8_t* data, int data_len,
                   int crc_ok, int response_time_ms);

#endif // LOG_WRITER_H
