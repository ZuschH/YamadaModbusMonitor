#ifndef MODBUS_CONFIG_H
#define MODBUS_CONFIG_H

#include <stdint.h>

typedef struct {
    char port[128];
    int baudrate;
    int databits;
    int stopbits;
    char parity; // 'N', 'E', 'O'
    int poll_interval_ms;
    int timeout_ms;
} modbus_config_t;

int load_modbus_config(const char* filename, modbus_config_t* config);

#endif // MODBUS_CONFIG_H
