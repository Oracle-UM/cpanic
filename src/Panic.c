#include "Panic.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

enum { ERR_PANIC = 101 };

noreturn void panic(void) {
    fprintf(stderr, "%s", "panicked\n");
    exit(ERR_PANIC);
}

noreturn void _panic_msg(
    char const* const file,
    char const* const func,
    size_t const line,
    char const* const fmt,
    ...
) {
    fprintf(stderr, "panicked at '");
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fprintf(
        stderr,
        "'\n"
        "file: %s\n"
        "function: %s\n"
        "line: %zu\n",
        file,
        func,
        line
    );
    exit(ERR_PANIC);
}
