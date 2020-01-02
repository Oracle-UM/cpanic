#ifndef PANIC_H
#define PANIC_H

#include <stddef.h>
#include <stdnoreturn.h>

noreturn void panic(void);

#define panic_msg(FMT, ...) \
    _panic_msg(__FILE__, __func__, __LINE__, FMT, __VA_ARGS__);

noreturn void _panic_msg(
    char const* file,
    char const* func,
    size_t line,
    char const* fmt,
    ...
);

#endif // PANIC_H
