#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#define MAX_PATH_LEN 256
#define MAX_STR_LEN  128

typedef struct {
    char serial_port[MAX_PATH_LEN];
    int baudrate;
    int poll_interval_ms;
    int timeout_ms;

    char log_dir[MAX_PATH_LEN];
    char log_format[MAX_STR_LEN];

    char ssh_target[MAX_STR_LEN];
    int ssh_port;
    char ssh_user[MAX_STR_LEN];
} config_t;

int load_config(const char* filename, config_t* config);

#endif // CONFIG_PARSER_H
