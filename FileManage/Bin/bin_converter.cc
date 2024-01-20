#include"bin_converter.hh"

#include <cstdlib> 
#include <cstdio>
#include <fstream> 
#include <string>

#include"debug.hh"
#include"files_exten.hh"

//convert file to binary format 
void* toBinConvert(const char* file_dir)
{
    char* temp_dir;
    FILE* res_file;
    FILE* temp_file;

    std::string str_file_dir;
    size_t dotindex;

    res_file = fopen(file_dir, "r");

    if(!res_file){
        ERR("file dont open");

        fclose(res_file);

        ERROM("get char to close");
        getchar();
        return NULL;
    }

    LOG("file open");

    str_file_dir = file_dir;    
    dotindex = str_file_dir.find(".");
    std::string str_temp_dir = str_file_dir.substr(0, dotindex);
    str_temp_dir.append(".temp");
    temp_dir = str_temp_dir.data();
    
    //temp_dir[0] = NoExtenDir(file_dir);

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

void* toHexConvert(const char* file_dir, const char* targ_dir){

    return NULL;
}