#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>  // for perror only


int main(int argc, char* argv[]){
    if(argc == 1 || argc == 2){
        puts("Too few arguments");
        exit(EXIT_FAILURE);
    }
    
    int source_fd = open(argv[1], O_RDONLY);
    int destination_fd = open(argv[2], O_WRONLY | O_CREAT, 0644);
    char buf[4096] = {};

    if(source_fd == -1)
        perror(argv[1]);
    if(destination_fd == -1)
        perror(argv[2]);

    return 0;
}