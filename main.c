#include"flags_analys.h"
#include"file_copy.h"
#include"bin_converter.h"
#include"debug.h"
#include"system.h"

int main(const int argc, const char* argv[])
{
    LOG("main start");
    char* _buf;

    LOG("%s", "sys scan start");
    if(sysscan() == 'W'){
        LOG("%s", "is WINDOWS");
    } 

    //fbinconv("E:\\project\\FileManageC\\res\\Noize MC - Egoizm.mp3");

    //txtfcopy("E:\\project\\FileManageC\\res\\.txt", ".temp");
    
    LOG("main end");
    getchar();
}    