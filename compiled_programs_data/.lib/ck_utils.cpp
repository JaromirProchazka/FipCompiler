#include "ck_utils.hpp"

#include <cstdio>
#include <cstdarg>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdio.h>

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
    // return 0;
}

static std::size_t already_allocated = 0;
void *ckrt_malloc(int size)
{
    auto res = malloc((std::size_t)size);
    // already_allocated += (std::size_t)size;
    // if (!res)
    // {
    //     // ckrt_printf("[ckrt_malloc] malloc returned NULL!\n");
    // }
    // else
    // {
    //     // ckrt_printf("[ckrt_malloc] malloced '%p'\n", res);
    // }
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

static clock_t clock_start = 0;

void ckrt_measure_cpu_time(void)
{
    if (clock_start == 0)
    {
        clock_start = clock();
    }
    else
    {
        clock_t end = clock();
        double elapsed_sec = (double)(end - clock_start) / CLOCKS_PER_SEC;
        printf("Now already malloced in total %uB\n", (unsigned int)already_allocated);
        printf("Elapsed CPU time: %.6f\n", elapsed_sec);
        clock_start = 0;
    }
}

// }