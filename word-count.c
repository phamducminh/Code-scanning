#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
#define BUFSIZE 256


    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    // Open the file in read mode
    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        fprintf(stderr, "Error: Unable to open the file '%s'.\n", argv[1]);
        return -1;
    }

    // Seek to the end of the file to determine its size
    if (fseek(file, 0, SEEK_END) != 0) {
        fprintf(stderr, "Error: Unable to determine the file size.\n");
        fclose(file);
        return -1;
    }

    // Get the file size in bytes
    long filesize = ftell(file);
    if (filesize == -1L) {
        fprintf(stderr, "Error: Unable to retrieve the file size.\n");
        fclose(file);
        return -1;
    }

    printf("File size: %ld bytes\n", filesize);

    // Close the file and exit
    fclose(file);
    return 0;
}