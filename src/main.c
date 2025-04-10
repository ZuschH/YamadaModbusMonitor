#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dialog_ui.h"

void print_version() {
    printf("Yamada Modbus Monitor v1.0.0\n");
    printf("Developed by ZuschH with AI co-engineering (ChatGPT)\n");
}

void print_easteregg() {
    printf("\n🐰 Yamada Modbus Monitor - Debug Bunny Mode Activated 🐰\n");
    printf("-------------------------------------------------------\n");
    printf("Name: GPT von der Bitwiese\n");
    printf("Role: Kabelsalat-Detektiv & Logfile-Orakel\n");
    printf("Version: Terminalfreund v1.0.0\n\n");
    printf("\"If you found this, you're either lost in the matrix or\n");
    printf("you've stared at too many Modbus CRCs.\"\n\n");
    printf("     (\\__/)\n     ( •_•)\n    / >💾  ← have a byte on me.\n\n");
    printf("🧠 Special thanks to you for keeping the system sane.\n\n");
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "--version") == 0) {
            print_version();
            return 0;
        } else if (strcmp(argv[1], "--easteregg") == 0) {
            print_easteregg();
            return 0;
        } else if (strcmp(argv[1], "--menu") == 0) {
            return dialog_show_menu("/var/log/YamadaDobby/modbus.log");
        } else if (strcmp(argv[1], "--reconfigure") == 0 && argc == 4) {
            printf("Reconfiguring %s to %s...\n", argv[2], argv[3]);
            // Implement live config update if desired
            return 0;
        } else {
            printf("Unknown option: %s\n", argv[1]);
            printf("Use --version, --easteregg, --menu, or --reconfigure\n");
            return 1;
        }
    } else {
        printf("Usage: %s [--version | --easteregg | --menu | --reconfigure key value]\n", argv[0]);
    }
    return 0;
}

