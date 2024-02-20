#include <stdio.h>

#include"flags_analys.h"
#include"file_copy.h"
#include"bin_converter.h"
#include"debug.h"
#include"system.h"

int main(const int argc, const char* argv[])
{
    LOG("main start");
	int i;

	//LOG(_OS);
    //fbinconv("E:\\project\\FileManageC\\res\\Noize MC - Egoizm.mp3");
    txtfcopy(argv[1], ".temp");
    
    LOG("main end");
    getchar();
	return 0;
}    
