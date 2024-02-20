#include"bin_converter.h"

#include <stdlib.h> 
#include <stdio.h>
#include <stdint.h>

#include"debug.h"
#include"file_exten.h"

typedef long long int int64;

//convert file to binary format 
void* fbinconv(const char* res_dir)
{
    uint8_t* _buf;
    char* _bin_dir;

    int64 _file_size;

    FILE* _res_file;
    FILE* _bin_file;

    _res_file = fopen(res_dir, "rb");

    if(!_res_file){
        ERR("resource file dont open");
        ERR("file dir: %s", res_dir);
        return NULL;
    }

    fseek(_res_file, 0, SEEK_END);
    _file_size = ftell(_res_file);
    fseek(_res_file, 0, SEEK_SET);

    LOG("file size = %lld bytes", _file_size);

    int64 _result = fread(_buf, sizeof(char), _file_size, _res_file);
    _result *= sizeof(uint8_t);

    LOG("buf size = %lld bytes", _result);
    
    if(_result != _file_size){
        ERR("read error");
        ERR("result = %lld bytes", _result);
        ERR("error buf");
        
        return NULL;
    }

    for(int i = 0; i < _file_size; i++){
        
    }

    _bin_dir = extreduc(res_dir, ".bin");
    _bin_file = fopen(_bin_dir, "wb");

    
   
    fclose(_res_file);

    return NULL;
}

void* toHexConvert(const char* res_dir, const char* targ_dir){

    return NULL;
}
