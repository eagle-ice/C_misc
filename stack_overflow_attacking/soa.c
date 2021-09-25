/*
 * =====================================================================================
 *
 *       Filename:  a.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/24/2021 05:28:21 PM
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

void shellcode(void)
{
    printf("xxxxxxxxxxxxxxxxxx\n");
    while(1) {
        sleep(1);
    }
}
void f(void)
{
    int a[4];
    a[8] = shellcode;
}

int main(int argc, char *argv[])
{
    f();
    printf("hello world\n");
    return 0;
}

