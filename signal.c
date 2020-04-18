#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig){
    printf("the signal is %d\n", sig);
    (void ) signal(SIGINT, SIG_DFL);
}

int main(){
    (void) signal(SIGINT, handler);
    while(1){
        printf("signal text\n");
        sleep(1);
    }
}