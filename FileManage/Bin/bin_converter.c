#include"bin_converter.h"

#include <stdlib.h> 
#include <stdio.h>
#include <fstream>
#include <cstring>

#include"debug.h"
#include"files_exten.h"

//convert file to binary format 
void* toBinConvert(const char* res_dir)
{
    FILE* res_file;
    FILE* temp_file;

    char* temp_dir;
    int dot_index;

    int temp_dir_len_w_extention;
    int res_dir_len_no_extention; 
    char* res_extention;
    const char* temp_extention = ".temp";

    res_file = fopen(res_dir, "r");

    if(!res_file){
        ERR("file dont open");

        fclose(res_file);

        ERROM("get char to close");
        getchar();
        exit(1);
    }

    LOG("file open");

    res_extention = strchr(res_dir, '.');
    if(res_extention == NULL){
        ERR("file dont has extention");
        fclose(res_file);
        getchar();
        exit(1);
    }

    res_dir_len_no_extention = strlen(res_dir) - strlen(res_extention);
    for(int i = 0; i < res_dir_len_no_extention; i++){
        temp_dir[i] = res_dir[i];
    }

    temp_dir_len_w_extention = res_dir_len_no_extention + strlen(temp_extention);
    for(int i = res_dir_len_no_extention; i < temp_dir_len_w_extention; i++){
        temp_dir[i] = temp_extention[i - (temp_dir_len_w_extention - strlen(temp_extention))];
    }
    temp_dir[temp_dir_len_w_extention] = '\0';

    temp_file = fopen(temp_dir, "w");

    if(!temp_file){
        ERR("temp file dont open");
        ERROM("get char to close");
        fclose(res_file);
        fclose(temp_file);
        getchar();
        exit(1);
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