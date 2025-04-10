/* inih -- simple .INI file parser
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __INI_H__
#define __INI_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

typedef int (*ini_handler)(void* user, const char* section, const char* name, const char* value);

typedef struct {
    ini_handler handler;
    void* user;
    int lineno;
    int error;
} ini_parser;

int ini_parse(const char* filename, ini_handler handler, void* user);
int ini_parse_file(FILE* file, ini_handler handler, void* user);

#ifdef __cplusplus
}
#endif

#endif /* __INI_H__ */
