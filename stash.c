#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s mode (distort or restore) path/to/input patt/to/output\n", argv[0]);
        exit(1);
    }
    const char *command = argv[1];
    if (strcmp(command, "distort") != 0 && strcmp(command, "restore") != 0)
    {
        fprintf(stderr, "Usage: %s mode (distort or restore) path/to/input patt/to/output\n", argv[0]);
        exit(1);
    }

    const char *input = argv[2];
    const char *output = argv[3];

    const int buffer_size = 32;
    char *buffer = (char*)malloc(buffer_size);
    FILE *input_f = fopen(input, "rb");
    FILE *output_f = fopen(input, "wb");
    int i = 0;
    while (!feof(input_f))
    {
        size_t count = fread(buffer, 1, buffer_size, input_f);
        if (count == 0)
            break;
        if (i == 0) {
            for (int j = 0; j < 4; j++) {
                buffer[j] = buffer[j] ^ 0x11;
            }
        }
        i++;
        fwrite(buffer, 1, count, output_f);
    }
    fclose(input_f);
    fclose(output_f);

    free(buffer);

    return 0;
}

