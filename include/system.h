#ifndef SYSTEM_H
#define SYSTEM_H 

#ifdef _WIN32
	#define _OS "WINDOWS"
#endif

#ifdef __unix__
	#define _OS "LINUX"
#endif

#endif //SYSTEM_H 
