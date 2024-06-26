#ifndef FLAG_H
#define FLAG_H

#include"flag.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

union Flags_code{
    struct {
        __u_char Creation   : 1;
        __u_char Open       : 1;
        __u_char Copy       : 1;
        __u_char Delete     : 1;
        // delete highter ---> 0000 <--- creation lower
    };
    unsigned char flags
} ;

const __u_char flagcode(const int argc, const char* argv[]);

#endif
