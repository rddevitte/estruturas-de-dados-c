#ifndef PRINTS_H
#define PRINTS_H

#ifdef __cplusplus
extern "C" {
#endif

#define PRINT_DBG(_msg, ...)     \
    printf("[%s:%d] " _msg "\n", \
        __func__, __LINE__ __VA_OPT__(, ) __VA_ARGS__);

#define PRINT_ERR(_msg, ...)              \
    fprintf(stderr, "[%s:%d] " _msg "\n", \
        __func__, __LINE__ __VA_OPT__(, ) __VA_ARGS__);

#ifdef __cplusplus
}
#endif

#endif // PRINTS_H
