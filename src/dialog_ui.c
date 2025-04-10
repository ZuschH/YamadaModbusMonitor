/* dialog_ui.c */
#include "dialog_ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Dummy implementation
int dialog_show_monitor(const DialogMonitorConfig *cfg) { return 0; }
int dialog_show_menu(const char *log_path) { return 0; }
int dialog_show_config_editor(const char *config_file) { return 0; }
int dialog_show_dashboard(const char *log_file) { return 0; }
