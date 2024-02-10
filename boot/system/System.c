#include"system.h"

#include<fstream>
#include<stdio.h>
#include<stdlib.h>

#include"debug.h"

char sysscan(){
    FILE* file = fopen("/bin", "r");
    if(file = fopen("/bin", "r")){
        LOG("%s", "LINUX\n");
        return 'L';
    }
    else if(file = fopen("C:\\Windows\\notepad.exe", "rb")){
        LOG("%s", "WINDOWS");
        return 'W';
    }
    return 0;
}