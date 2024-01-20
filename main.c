#include"flags_analys.h"
#include"bin_converter.h"
#include"debug.h"

int main(const int argc, const char* argv[])
{
    LOG(argv[0]);
    wasFlagsAllow(argc, argv);
    toBinConvert("E:\\project\\FileManageC\\res\\text.txt");
    
    LOG("main end");
    getchar();
}    

 