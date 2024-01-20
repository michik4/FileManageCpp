#include"bin_converter.h"

#include <stdlib.h> 
#include <stdio.h>
#include <fstream>

#include"debug.h"
#include"files_exten.h"

//convert file to binary format 
void* toBinConvert(const char* res_dir)
{
    FILE* res_file;
    FILE* temp_file;

    res_file = fopen(res_dir, "r");

    if(!res_file){
        ERR("file dont open");

        fclose(res_file);

        ERROM("get char to close");
        getchar();
        return NULL;
    }

    LOG("file open");
    const char* temp_dir = res_dir; 
    
    //temp_dir[0] = NoExtenDir(res_dir);

    LOG(temp_dir);
    temp_file = fopen(temp_dir, "w");

    if(!temp_file){
        ERR("temp file dont open");
        ERROM("get char to close");
        fclose(res_file);
        fclose(temp_file);
        getchar();
        return NULL;
    }
    LOG(temp_dir);
    LOG("temp file open");

    
    fclose(res_file);
    fclose(temp_file);

    return NULL;
}

void* toHexConvert(const char* res_dir, const char* targ_dir){

    return NULL;
}