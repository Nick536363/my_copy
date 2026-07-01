#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>  // for perror only

#define BUFFER_SIZE 4096

int main(int argc, char* argv[]){
    if(argc == 1 || argc == 2){
        puts("Too few arguments");
        exit(EXIT_FAILURE);
    }
    ssize_t bytes_read = 0;
    ssize_t bytes_write = 0;
    char buf[BUFFER_SIZE] = {};

    int source_fd = open(argv[1], O_RDONLY);
    if(source_fd == -1){
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }

    int destination_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(destination_fd == -1){
        perror(argv[2]);
        exit(EXIT_FAILURE);
    }

    bytes_read = read(source_fd, buf, BUFFER_SIZE);
    while(bytes_read > 0){
        if((bytes_write = write(destination_fd, buf, bytes_read)) == -1){
            perror("write()");
            exit(EXIT_FAILURE);
        }
        bytes_read = read(source_fd, buf, BUFFER_SIZE);
    }
    if(close(source_fd) == -1)
        perror("close()");
    if(close(destination_fd) == -1)
        perror("close()");
    return 0;
}