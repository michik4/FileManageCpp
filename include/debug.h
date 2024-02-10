#ifdef DEBUG
    #define AC_CYAN  "\x1b[36;1m"
    #define AC_GREEN "\x1b[32;1m"
    #define AC_RED   "\x1b[31;1m"
    #define AC_RESET "\x1b[0m"
    #define LOG(...)                                                                        \
    do {                                                                                    \
        fprintf(stderr, AC_CYAN "[INF] %s (%d)\t " AC_RESET, __FILE__, __LINE__);           \
        fprintf(stderr, __VA_ARGS__);                                                       \
        fprintf(stderr, "\n");                                                              \
    } while (0)   

    #define ERR(...)                                                                        \
    do {                                                                                    \
        fprintf(stderr, AC_RED "[ERR] %s (%d)\t " AC_RESET, __FILE__, __LINE__);            \
        fprintf(stderr, __VA_ARGS__);                                                       \
        fprintf(stderr, "\n");                                                              \
    } while (0)     

    #define ERROM(M) fprintf(stderr, AC_RED "[ERRO] %s\n" AC_RESET, M)
#else
    #define AC_CYAN
    #define AC_GREEN
    #define AC_RED
    #define AC_RESET
    #define LOG(...)
    #define ERR(...)
    #define ERROM(M)
#endif