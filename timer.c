#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(){
    int msec = 0, trigger = 50, itera = 0;
    clock_t before = clock();
    do{
        // usleep(10000);
        sleep(1);
        clock_t diff = clock() - before;
        msec = diff*1000/CLOCKS_PER_SEC;
        itera++;
        printf("%d second,10ms\n", msec);
    }while(msec < trigger);
    printf("takes %d second, %d milesecond, %d iteration", msec/1000, msec%1000, itera);
    return 0;
    // int msec = 0, trigger = 50, itera = 0;
    // clock_t before = clock();
    // do {
    //     clock_t diff = clock() - before;
    //     msec = diff*1000/CLOCKS_PER_SEC;
    //     itera++;
    //     printf("%d\n", msec);
    //     if(msec%10000 == 0){
    //         printf("%d milesecond ,use schedule\n", msec);
    //     }
    // }while(msec < trigger);
    // printf("takes %d second, %d milesecond, %d iteration", msec/1000, msec%1000, itera);
}