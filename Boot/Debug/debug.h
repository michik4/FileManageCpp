#ifdef DEBUG
    #define AC_CYAN  "\x1b[36;1m"
    #define AC_GREEN "\x1b[32;1m"
    #define AC_RED   "\x1b[31;1m"
    #define AC_RESET "\x1b[0m"
    #define LOG(...)                                                        \
    do {                                                                    \
        fprintf(stderr, AC_CYAN "[INFO] %s (%d): ", __FILE__, __LINE__);    \
        fprintf(stderr, __VA_ARGS__);                                       \
        fprintf(stderr, AC_RESET);                                          \
        fputc('\n', stderr);                                                \
    } while (0)                                                           
        
    #define LOGF(M) fprintf(stderr, AC_CYAN "[INFO] %s:\t %s\n" AC_RESET, __func__, M)
    #define ERR(M) fprintf(stderr, AC_RED "[ERRO] %s [%d]:\t %s\n" AC_RESET, __FILE__, __LINE__, M)
    #define ERROM(M) fprintf(stderr, AC_RED "[ERRO] %s\n" AC_RESET, M)
#else
    #define AC_CYAN
    #define AC_GREEN
    #define AC_RED
    #define AC_RESET
    #define LOG(M)
    #define ERR(M)
    #define ERROM(M)
#endif