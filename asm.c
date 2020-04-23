#include <stdio.h>
#include <string.h>

char * my_strcpy(char * src, char * dest){
    __asm__ __volatile__("cld\n"
        "1:\tlodsb\n\t"
        "stosb\n\t"
        "testb %%al,%%al\n\t"
        "jne 1b"
        ::"S" (src),"D" (dest):);
    return dest;
}

// int strcom(char * cs, char * ct, int count){
//     register int __res;
//     asm("cld\n"
//     "1:\tdecl %3\n\t"
//     "js 2f\n\t"
//     "lodsb\n\t"
//     "scasb\n\t"
//     "jne 3f\n\t"
//     "testb %%al,%%al\n\t"
//     "jne 1b\n\t"
//     "2:\txorl %%eax,%%eax\n\t"
//     "jmp 4f\n"
//     "3:\tmovl $1,%%eax\n\t"
//     "jl 4f\n"
//     "negl %%eax\n"
//     "4:"
//     :"=a"(__res):"D"(cs),"S"(ct),"c"(count):"si","di","cx");
//     return __res;
// }

int main(){
    char * a = "hello";
    char b[100];
    char * d = "hell";
    char * c = my_strcpy(a, b);
    printf("%s\n", c);
    printf("%s", b);
    // int g = strcom(a, d, 3);
    // printf("%d", g);
    return 0;
}