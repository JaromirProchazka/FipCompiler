#include "ck_utils.hpp"

#include <cstdio>
#include <cstdarg>
#include <iostream>
#include <vector>

std::ostream *ckrt_out = &std::cout;

// extern "C"
// {
int ckrt_printf(const char *s, ...)
{
    static std::vector<char> buffer;
    va_list va;
    va_start(va, s);
    va_list va2;
    va_copy(va2, va);
    auto rv2 = std::vsnprintf(nullptr, 0, s, va2);
    va_end(va2);
    if (rv2 < 0) // vsnprintf failed
    {
        std::vsnprintf(nullptr, 0, s, va);
    }
    else
    {
        auto rsize = (std::size_t)rv2 + 1; // ending zero
        if (rsize >= buffer.size())
            buffer.resize(rsize);
        auto rv = std::vsnprintf(buffer.data(), buffer.size(), s, va);
        if (rv == rv2)
        {
            ckrt_out->write(buffer.data(), rv);
            ckrt_out->flush();
        }
    }
    va_end(va);

    // change for fip
    rv2 = (rv2 != -1) ? 0 : 1;
    // change for fip

    return rv2;
}

void *ckrt_malloc(int size)
{
    auto res = malloc((std::size_t)size);
    if (!res)
    {
        // ckrt_printf("[ckrt_malloc] malloc returned NULL!\n");
    }
    else
    {
        // ckrt_printf("[ckrt_malloc] malloced '%p'\n", res);
    }
    return res;
}

int ckrt_scanf(const char *s, ...)
{
    va_list va;
    va_start(va, s);
    int rv = vscanf(s, va);
    va_end(va);

    return rv;
}

int ckrt_sprintf(char *b, const char *s, ...)
{
    va_list va;
    va_start(va, s);
    int rv = vsprintf(b, s, va);
    va_end(va);

    return rv;
}

int ckrt_sscanf(const char *b, const char *s, ...)
{
    va_list va;
    va_start(va, s);
    int rv = vsscanf(b, s, va);
    va_end(va);

    return rv;
}

void ckrt_memset(void *d, int s, int l)
{
    wmemset((wchar_t *)d, s, l);
}
// }