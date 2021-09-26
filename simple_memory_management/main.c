/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/26/2021 08:02:27 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "mempool.h"

int main(int argc, char *argv[])
{
    pool_init();
    pool_info();
    char *p = NULL;
    char *q = NULL;
    p = (char *)pool_malloc(100);
    q = (char *)pool_malloc(24);
    memcpy(p, "hello world\n", 15);
    printf("%s\n", p);
    pool_info();
    pool_free(p);
    pool_free(q);
    pool_info();
    return 0;
}

