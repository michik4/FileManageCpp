#ifndef SYSTEM_H
#define SYSTEM_H 

#ifdef _WIN32
#define _FILE __FILE__
#define _OS "WINDOWS"
#endif

#ifdef __unix__
#include <unistd.h>
#include <linux/limits.h>
#define _FILE getcwd()                                  
#define _OS "LINUX"                                     
#endif

#endif //SYSTEM_H 