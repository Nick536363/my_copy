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
    if(source_fd == -1)
        perror(argv[1]);

    return 0;
}