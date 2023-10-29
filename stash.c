#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void saveFile(const char* filename, char* data, int size, const char* mode) {
    FILE* file = fopen(filename, "r+");
    if (file != NULL) {
        fwrite(data, 1, 4, file);
        fclose(file);
        if (strcmp(mode, "distort") == 0) {
            printf("File successfully distorted\n");
        }
        else if (strcmp(mode, "restore") == 0) {
            printf("File successfully restored\n");
        }
        
    } else {
        printf("Error opening file for saving.\n");
    }
}


int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s mode (distort or restore) path/to/file\n", argv[0]);
        exit(1);
    }
    const char *command = argv[1];
    if (strcmp(command, "distort") != 0 && strcmp(command, "restore") != 0)
    {
        fprintf(stderr, "Usage: %s mode (distort or restore) path/to/file\n", argv[0]);
        exit(1);
    }

    const char *filename = argv[2];
    
    FILE* file = fopen(filename, "rb");
    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        int size = ftell(file);
        fseek(file, 0, SEEK_SET);

        if (size >= 4) {
            char data[4];
            fread(data, sizeof(char), 4, file);
            for (int i = 0; i < 4; i++) {
                data[i] ^= 0x11;
            }
            fclose(file);
            saveFile(filename, data, 4, command);
        } else {
            printf("File size is less than 4 bytes.\n");
        }
    } else {
        printf("Error opening file.\n");
    }

    return 0;
}
