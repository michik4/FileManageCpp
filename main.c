#include <stdio.h>

#include "flag.h"
#include "copy.h"
#include "bin_converter.h"
#include "debug.h"
#include "system.h"
#include "exten.h"

int main(const int argc, const char* argv[])
{
    LOG("main start");
	
    int i;
    char* str;

	//LOG(_OS);
    //txtfcopy(argv[1], ".temp");
    //binfcopy(argv[1]);
    str = oext(argv[1]);
    LOG("%s", str);

    LOG("main end");

    #ifdef DEBUG
        getchar();
    #endif

	return 0;
}    
