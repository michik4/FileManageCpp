#include"flags_analys.h"
#include"txt_exten_file_copy.h"
#include"bin_converter.h"
#include"debug.h"

int main(const int argc, const char* argv[])
{
    LOG(argv[0]);
    copyToTempExten("E:\\project\\FileManageC\\res\\text123.txt");
    
    LOG("main end");
    getchar();
}    

