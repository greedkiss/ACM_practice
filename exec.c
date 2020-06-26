#include <stdio.h>
#include <elf.h>
#include <stdlib.h>
unsigned long long addr;
char * buffer = NULL;

void exec(unsigned long long * rsp){
    // printf("%p", rsp);
    *rsp =(unsigned long long)buffer + (unsigned long long)addr;
    // *rsp = 0x4006be;
    // *rsp =(unsigned long long)buffer;
    // printf("%lp", rsp);
} 

void sys_call(unsigned long long addr){
    __asm__("ljmp *(%0)\n\t"
    ::"D" (addr):);
}

void (*fun) ();

int main(){
    buffer = (char *)malloc(9*1024);
    FILE* elf;
    elf = fopen("/home/flipped/code/acm/hello", "r+");
    int rc;
    fseek(elf, 0, SEEK_SET);
    while((rc = fread(buffer, sizeof(char), 9*1024, elf))!=0);
    addr = (unsigned long long)((Elf64_Ehdr *) buffer)->e_entry;
    unsigned long long rsp =(unsigned long long)buffer;
    // fun = (void *) rsp;
    // (*fun)();

    sys_call(rsp);
    return 0;
}
