#include"flags_analys.h"
#include"txt_exten_file_copy.h"
#include"bin_converter.h"
#include"debug.h"

int main(const int argc, const char* argv[])
{
    LOG(argv[0]);
    txtfcopy("E:\\project\\FileManageC\\res\\text123.txt", ".temp");
    
    LOG("main end");
    getchar();
}    