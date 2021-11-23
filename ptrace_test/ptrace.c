/*
 * =====================================================================================
 *
 *       Filename:  ptrace.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2021年11月23日 08时56分03秒
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
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/user.h>

int main(int argc, char *argv[])
{
    pid_t child;
    struct user_regs_struct regs;

    child = fork();
    if (child == 0) {
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        execl("/bin/ls", "ls", NULL);
    } else {
        wait(NULL);
        ptrace(PTRACE_CONT, child, NULL, &regs);
        printf("register: rdi[%lld], rsi[%lld], rdx[%lld], rax[%lld], orig_rax[%lld]\n",
                regs.rdi, regs.rsi, regs.rdx, regs.rax, regs.orig_rax);
        ptrace(PTRACE_CONT, child, NULL, NULL);
        sleep(1);
    }
    return 0;
}

