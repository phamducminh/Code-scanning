#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
#define BUFSIZE 256

int read_file(const char *filename) {
    FILE* ptr = fopen(filename, "r");
    
    if (ptr == NULL) {
        printf("File cannot be opened.\n");
        return(-1);
    }
    
    char buff[BUFSIZE];
    
    while (fgets(buff, BUFSIZE, ptr) != NULL) {
        printf("%s", buff);
    }
        
    return 0; 
}

unsigned long fsize(char* file)
{
    FILE * f = fopen(file, "rb");
    if (!f) {
        fprintf(stderr, "Error: Unable to open the file '%s'.\n", file);
        return -1;
    }
    fseek(f, 0, SEEK_END);
    unsigned long len = (unsigned long)ftell(f);
    fclose(f);
    return len;
}
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    long filesize = fsize(argv[1]);
    if (filesize == -1L) {
        return -1;
    } else {
        printf("File size: %ld bytes\n", filesize);
    }
    
    return 0;
}