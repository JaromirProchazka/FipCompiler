#include <cstdio>

#ifdef __cplusplus
extern "C"
{
#endif

    void *ckrt_malloc(int size);
    int ckrt_printf(const char *format, ...);

#ifdef __cplusplus
}
#endif