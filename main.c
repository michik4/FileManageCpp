#include <stdio.h>

#include"flag.h"
#include"copy.h"
#include"bin_converter.h"
#include"debug.h"
#include"system.h"

int main(const int argc, const char* argv[])
{
    LOG("main start");
	int i;

	//LOG(_OS);
    //txtfcopy(argv[1], ".temp");
    binfcopy(argv[1]);
    
    LOG("main end");

    #ifdef DEBUG
        getchar();
    #endif

	return 0;
}    
