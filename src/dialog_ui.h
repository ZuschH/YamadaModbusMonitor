/* dialog_ui.h */
#ifndef DIALOG_UI_H
#define DIALOG_UI_H

typedef struct {
    const char *log_file;
    int auto_scroll;
} DialogMonitorConfig;

int dialog_show_monitor(const DialogMonitorConfig *cfg);
int dialog_show_menu(const char *log_path);
int dialog_show_config_editor(const char *config_file);
int dialog_show_dashboard(const char *log_file);

#endif // DIALOG_UI_H
