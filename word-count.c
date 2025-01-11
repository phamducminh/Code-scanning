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

    // Validate the file name length
    if (snprintf(NULL, 0, "wc -c < '%s'", argv[1]) >= BUFSIZE) {
        fprintf(stderr, "Error: File name is too long.\n");
        return -1;
    }

    // Construct the command safely using snprintf
    char cmd[BUFSIZE];
    if (snprintf(cmd, sizeof(cmd), "wc -c < '%s'", argv[1]) >= sizeof(cmd)) {
        fprintf(stderr, "Error: Command buffer overflow.\n");
        return -1;
    }

    // Execute the system command
    int ret = system(cmd);
    if (ret == -1) {
        fprintf(stderr, "Error: Failed to execute system command.\n");
        return -1;
    }

    return 0;
}