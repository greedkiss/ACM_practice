#include <stdio.h>

void print(){
    printf("hello\n");
}

void exec(unsigned long long * rsp){
    // printf("%p", rsp);
    *rsp = (unsigned long long*)(&print);

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
    sys_call();
    return 0;
}