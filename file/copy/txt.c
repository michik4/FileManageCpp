#include"copy.h"

#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

#include"debug.h"
#include"exten.h"

//copy file with variable extention to the current catalog  
void* txtfcopy(const char* resdir, const char* ext)
{    
    FILE* _resf;
    FILE* _tempf;

    int _bufsize;
    int _line;
    
    char* _buf;
    char* _pbuf;

    const char* _tempdir = (char*)calloc(260, sizeof(_tempdir));
    const char* _tempext = ext;
	
	//resource file dir don't exist error
	if(resdir == NULL){
		ERR("Res dir is NULL");
		return 0;	
	}

	LOG("%s", resdir);
    _resf = fopen(resdir, "r");
	
    //resource file don't open error
    if(!_resf){
        ERR("file dont open");
        fclose(_resf);
        return NULL;
    }

    LOG("file open");

    //extention editing error
    if(!(_tempdir = exted(resdir, _tempext))){
        return NULL;
    }

    //temp file don't open error
    if(!(_tempf = fopen(_tempdir, "w"))){
        ERR("temp file dont open");
        fclose(_resf);
        fclose(_tempf);
        return NULL;
    }

    LOG("temp dir: %s", _tempdir);
    LOG("temp file open");

    LOG("copy start");
    
    #ifdef DEBUG
        fprintf(stderr, "%s%s%s", "\n** ", _tempdir, " **\n");
    #endif

    _line = 1;
    _bufsize = 100 * sizeof(_buf);
    
    //copy proc
    do{
        _buf = (char*)calloc(_bufsize * sizeof(_buf), sizeof(_buf));
        _pbuf = fgets(_buf, _bufsize , _resf);

        if(!_pbuf && !feof(_resf)){
            ERR("read file err");
            free(_buf);
            fclose(_resf);
            fclose(_tempf);
            return NULL;
        }

        fprintf(_tempf, "%s", _buf);

        #ifdef DEBUG
            fprintf(stderr, "%-8d%s%s", _line++, "-| ", _buf); 
        #endif

        free(_buf);
        _buf = NULL;

    }while(!feof(_resf));

    #ifdef DEBUG
        fprintf(stderr, "\n\n");
    #endif

    LOG("file copy success");

    fclose(_resf);
    fclose(_tempf);

    return _tempf;
}
