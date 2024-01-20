#include"bin_converter.hh"

#include <cstdlib> 
#include <cstdio>
#include <fstream> 

void* toHexConvert(const char* file_dir, const char* targ_dir)
{
    FILE* res_file;
    FILE* targ_file;

    res_file = fopen(file_dir, "rb");
    if(!res_file){
        fprintf(stderr, "[ERRO] %s [%d] : %s\n", __FILE__, __LINE__, "file dont open");

        fclose(res_file);
        fclose(targ_file);

        fprintf(stdout, "[ERRO] get char to close\n");
        getchar();
        exit(1);
    } else {
        fprintf(stderr, "file open");
    } 
  
    
    
    return nullptr;
}