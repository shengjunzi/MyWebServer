#include"util.h"
#include<stdio.h>
#include<stdlib.h>

//异常处理函数
void errif(bool condition, const char *errmsg) {
    if(condition) {
        perror(errmsg);
        exit(EXIT_FAILURE);
    }
}