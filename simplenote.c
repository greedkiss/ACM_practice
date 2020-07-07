#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

void usage(char *prog_name, char* file_name){
    printf("%s %s", prog_name, file_name);
    exit(0);
}

void fatal(char *message){
    char error_message[100];
    strcpy(error_message, "[!!fatal error]");
    strncat(error_message, message, 83);
    perror(error_message);
    exit(-1);
}

void *ec_malloc(unsigned int size){
    void *ptr;
    ptr = malloc(size);
    if(ptr == NULL){
        fatal("in ec_malloc on memory allocation");
    }
    return ptr;
}

int main(int argc, char * argv[]){
    int fd;
    char *buffer , *datafile;
    buffer = (char*)ec_malloc(100);
    datafile = (char *)ec_malloc(20);
    strcpy(datafile, "/home/flipped/code/acm/test_file");

    if(argc < 2)
        usage(argv[0], datafile);
    strcpy(buffer, argv[1]);

    printf("[DEBUG ] buffer %p:  %s", buffer, buffer);

    strncat(buffer, "\n", 1);

    fd = open(datafile, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
    if(fd == -1)
        fatal("in main() while opening file");
    
    if(write(fd, buffer, strlen(buffer)) == -1)
        fatal("in main() while writing file");
    
    if(close(fd) == -1)
        fatal("in main() while closing file");
    free(buffer);
    free(datafile);

    return 0;
}