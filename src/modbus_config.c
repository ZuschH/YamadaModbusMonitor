#ifndef MODBUS_CONFIG_H
#define MODBUS_CONFIG_H

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ini.h"

typedef struct {
    char port[128];
    int baudrate;
    int databits;
    int stopbits;
    char parity; // 'N', 'E', 'O'
    int poll_interval_ms;
    int timeout_ms;
} modbus_config_t;

static int modbus_ini_handler(void* user, const char* section, const char* name, const char* value) {
    modbus_config_t* config = (modbus_config_t*)user;

    #define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0

    if (MATCH("serial", "port")) {
        strncpy(config->port, value, sizeof(config->port) - 1);
    } else if (MATCH("serial", "baudrate")) {
        config->baudrate = atoi(value);
    } else if (MATCH("serial", "databits")) {
        config->databits = atoi(value);
    } else if (MATCH("serial", "stopbits")) {
        config->stopbits = atoi(value);
    } else if (MATCH("serial", "parity")) {
        config->parity = value[0];
    } else if (MATCH("modbus", "poll_interval_ms")) {
        config->poll_interval_ms = atoi(value);
    } else if (MATCH("modbus", "timeout_ms")) {
        config->timeout_ms = atoi(value);
    } else {
        return 0; // unknown entry
    }
    return 1;
}

static int load_modbus_config(const char* filename, modbus_config_t* config) {
    memset(config, 0, sizeof(modbus_config_t));
    return ini_parse(filename, modbus_ini_handler, config);
}

#endif // MODBUS_CONFIG_H
