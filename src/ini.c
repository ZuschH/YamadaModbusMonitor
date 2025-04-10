#include "ini.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 200

static char* rstrip(char* s) {
    char* p = s + strlen(s);
    while (p > s && isspace((unsigned char)(*--p)))
        *p = '\0';
    return s;
}

static char* lskip(const char* s) {
    while (*s && isspace((unsigned char)(*s)))
        s++;
    return (char*)s;
}

static char* find_char_or_comment(const char* s, char c) {
    int was_whitespace = 0;
    while (*s && *s != c && !(was_whitespace && *s == ';')) {
        was_whitespace = isspace((unsigned char)(*s));
        s++;
    }
    return (char*)s;
}

static char* strncpy0(char* dest, const char* src, size_t size) {
    strncpy(dest, src, size);
    dest[size - 1] = '\0';
    return dest;
}

int ini_parse_file(FILE* file, ini_handler handler, void* user) {
    char line[MAX_LINE];
    char section[50] = "";
    char prev_name[50] = "";

    char* start;
    char* end;
    char* name;
    char* value;
    int lineno = 0;
    int error = 0;

    while (fgets(line, MAX_LINE, file) != NULL) {
        lineno++;
        start = lskip(rstrip(line));

        if (*start == ';' || *start == '#') {
            continue;
        } else if (*start == '[') {
            end = strchr(start + 1, ']');
            if (end == NULL) {
                return lineno;
            } else {
                *end = '\0';
                strncpy0(section, start + 1, sizeof(section));
                *prev_name = '\0';
            }
        } else if (*start && *start != ';') {
            end = find_char_or_comment(start, '=');
            if (*end != '=') {
                return lineno;
            }
            *end = '\0';
            name = rstrip(start);
            value = lskip(end + 1);
            rstrip(value);

            strncpy0(prev_name, name, sizeof(prev_name));
            if (!handler(user, section, name, value) && !error)
                error = lineno;
        }
    }

    return error;
}

int ini_parse(const char* filename, ini_handler handler, void* user) {
    FILE* file;
    int error;

    file = fopen(filename, "r");
    if (!file) return -1;
    error = ini_parse_file(file, handler, user);
    fclose(file);
    return error;
}
