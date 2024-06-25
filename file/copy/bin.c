#include "copy.h"

#include <stdio.h>
#include <stdlib.h>

#include "exten.h"
#include "debug.h"

void* binfcopy(const char* resdir){
    
    FILE* _resf;
    FILE* _binf;


    size_t _resfsize;

    __u_char _buf;

    const char* _binfdir = (char*)calloc(260, sizeof(_binfdir));

    #ifdef DEBUG
        size_t _binfsize;
    #endif

    // resource file don't open error 
    if(!(_resf = fopen(resdir, "rb"))){
        ERR("res file dont open");
        fclose(_resf);
        return NULL;
    }

    LOG("res file open");

    // resource file size
    fseek(_resf, 0L, SEEK_END);
    _resfsize = ftell(_resf);
    fseek(_resf, 0L, SEEK_SET);

    LOG("res file size = %zd", _resfsize);

    // binary file extention don't edit error 
    if(!(_binfdir = exted(resdir, ".bin"))){
        ERR("bin file extention dont edit");
        fclose(_resf);
        return NULL;
    }

    // binary file don't open error
    if(!(_binf = fopen(_binfdir, "wb"))){
        ERR("bin file dont open");
        fclose(_resf);
        fclose(_binf);
        return NULL;
    }

    LOG("bin file open");
    LOG("start copy");

    // copy proc
    for(size_t i = 1; i <= _resfsize; ++i){
        fread(&_buf, sizeof(_buf), 1, _resf);
        fwrite(&_buf, sizeof(_buf), 1, _binf);
        fseek(_resf, i, SEEK_SET);
    }    

    LOG("copy end");

    fclose(_resf);

    #ifdef DEBUG
        fseek(_binf, 0l, SEEK_END);
        _binfsize = ftell(_binf);
        fseek(_binf, 0l, SEEK_SET);

        LOG("bin file size = %zd", _binfsize);
    #endif

    fclose(_binf);

    // checking the success of the copy
    if(_resfsize == _binfsize){ OK("files are the same");}
    else{                       ERR("files are not the same");}


}
