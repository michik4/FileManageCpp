#include"file_copy.h"

#include <stdlib.h> 
#include <stdio.h>
#include <fstream>
#include <cstring>

#include"debug.h"
#include"file_exten.h"

//copy file to var extention
void* txtfcopy(const char* res_dir, const char* ext)
{    
    FILE* _res_file;
    FILE* _temp_file;

    int _bufsize;
    int _line;
    
    char* _buf;
    char* _pbuf;

    const char* _temp_dir = (char*)calloc(260, sizeof(_temp_dir));
    const char* _temp_ext = ext;

    _res_file = fopen(res_dir, "r");

    //resource file don't open exeption
    if(!_res_file){
        
        ERR("file dont open");

        fclose(_res_file);

        return NULL;
    }

    LOG(res_dir);
    LOG("file open");

    if(!(_temp_dir = extreduc(res_dir, _temp_ext))){
        return NULL;
    }

    _temp_file = fopen(_temp_dir, "w");
    free((void*)_temp_dir);

    //temp file don't open exeption
    if(!_temp_file){

        ERR("temp file dont open");

        fclose(_res_file);
        fclose(_temp_file);

        return NULL;
    }

    LOG("temp dir: %s", _temp_dir);
    LOG("temp file open");

    LOG("copy start");
    
    #ifdef DEBUG
        fprintf(stderr, "%s%s%s", "\n** ", _temp_dir, " **\n");
    #endif

    _line = 1;
    _bufsize = 100 * sizeof(_buf);
    
    //copy proc
    do{
        _buf = (char*)calloc(_bufsize * sizeof(_buf), sizeof(_buf));
        _pbuf = fgets(_buf, _bufsize , _res_file);

        if(!_pbuf && !feof(_res_file)){

            ERR("read file err");

            free(_buf);
            fclose(_res_file);
            fclose(_temp_file);

            return NULL;
        }

        fprintf(_temp_file, "%s", _buf);

        #ifdef DEBUG
            fprintf(stderr, "%-8d%s%s", _line++, "-| ", _buf); 
        #endif

        free(_buf);
        _buf = NULL;

    }while(!feof(_res_file));

    #ifdef DEBUG
        fprintf(stderr, "\n\n");
    #endif

    LOG("file copy success");

    fclose(_res_file);
    fclose(_temp_file);

    return _temp_file;
}