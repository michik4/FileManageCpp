#include"file_exten.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include"debug.h"
//reduction file extention
char* extreduc(const char* res_dir, const char* desired_ext){
    
    const char* _res_dir;
    const char* _res_ext;
    char* _desired_dir;
    int _res_dir_len_no_ext;
    int _desired_dir_len_w_ext;

    _res_dir = res_dir;
    _desired_dir = (char*)malloc(260);
    _res_ext = strchr(_res_dir, '.');

    if(_res_ext == NULL){
        ERR("file don't has extention");
        return NULL;
    }

    if(!strcmp(_res_dir, _res_ext)){
        ERR("file is dotfile");
        return NULL;
    }

    _res_dir_len_no_ext = strlen(_res_dir) - strlen(_res_ext);

    for(int i = 0; i < _res_dir_len_no_ext; i++){
        _desired_dir[i] = _res_dir[i];
    }

    _desired_dir_len_w_ext = _res_dir_len_no_ext + strlen(desired_ext);

    for(int i = _res_dir_len_no_ext; i < _desired_dir_len_w_ext; i++){
        _desired_dir[i] = desired_ext[i - _res_dir_len_no_ext];
    }

    _desired_dir[_desired_dir_len_w_ext] = '\0';

    return _desired_dir;
}
