#include <cstdio>

#ifdef __cplusplus
extern "C"
{
#endif

    void *ckrt_malloc(int size);
    int ckrt_printf(const char *format, ...);

    /// Call once to mark the start time, second time to print time passed
    void ckrt_measure_cpu_time(void);

#ifdef __cplusplus
}
#endif