#include"exten.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include"debug.h"

//reduction file extention
char* exted(const char* fdir, const char* des_ext){
    
    const char* _rdir;
    const char* _rext;
    char* _desdir;
    int _res_dir_len_no_ext;
    int _des_dir_len;

    _rdir = fdir;
    _desdir = (char*)malloc(260);
    _rext = strchr(_rdir, '.');

    // file without extention error
    if(_rext == NULL){
        ERR("file don't has extention");
        return NULL;
    }

    // dotfile check
    if(!strcmp(_rdir, _rext)){
        LOG("file is dotfile");
    }

    _res_dir_len_no_ext = strlen(_rdir) - strlen(_rext);

    for(int i = 0; i < _res_dir_len_no_ext; i++){
        _desdir[i] = _rdir[i];
    }

    _des_dir_len = _res_dir_len_no_ext + strlen(des_ext);

    for(int i = _res_dir_len_no_ext; i < _des_dir_len; i++){
        _desdir[i] = des_ext[i - _res_dir_len_no_ext];
    }

    _desdir[_des_dir_len] = '\0';

    return _desdir;
}

// output extention of file
char* oext(const char* fdir){
    char* _fext;
    _fext = strchr(fdir, '.'); 
    return ++_fext;
}