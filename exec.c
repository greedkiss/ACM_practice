#include <stdio.h>
#include <elf.h>
#include <stdlib.h>
unsigned long long * addr;
char * buffer = NULL;

void exec(unsigned long long * rsp){
    // printf("%p", rsp);
    *rsp =(unsigned long long)buffer + (unsigned long long)addr;
    // printf("%lp", rsp);
}

void sys_call(){
    __asm__("lea 8(%%rbp), %%rdi\n\t"
    "pushq %%rdi\n\t"
    "call exec\n\t"
    "leave\n\t"
    "ret\n\t"
    :::);
}

int main(){
    buffer = (char *)malloc(9*1024);
    FILE* elf;
    elf = fopen("/home/flipped/code/acm/hello", "r+");
    int rc;
    while((rc = fread(buffer, sizeof(char), 1024, elf))!=0);
    addr = (unsigned long long *)((Elf64_Ehdr *) buffer)->e_entry;
    sys_call();
    return 0;

}