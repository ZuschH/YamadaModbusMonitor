typedef struct {
    struct {
        char port[64];
        int baudrate;
        int databits;
        int stopbits;
        char parity[8];
        char mode[8];
        char protocol[16];
    } serial;

    struct {
        int timeout_ms;
        bool crc_check;
        bool log_invalid_crc;
    } modbus;

    struct {
        char log_dir[128];
        char log_format[16];
        bool rotate;
        int max_file_size_kb;
    } logging;

    struct {
        bool enable;
        bool auto_launch;
        int refresh_interval_ms;
    } ui;

    struct {
        char ssh_target[128];
        int ssh_port;
        bool rsync_enabled;
        int sync_interval_sec;
    } network;

    struct {
        bool run_as_daemon;
        char pid_file[128];
    } service;

} MonitorConfig;
