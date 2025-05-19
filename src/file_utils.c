#include <stdio.h>
#include <stdlib.h>
#include "../include/file_utils.h"

// Read the content of a file into a string
char* read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }
    
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char *content = (char *)malloc(length + 1);
    if (content) {
        fread(content, 1, length, file);
        content[length] = '\0';
    }
    
    fclose(file);
    return content;
}

// Write a string to a file
void write_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    fputs(content, file);
    fclose(file);
}