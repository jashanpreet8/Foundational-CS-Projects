#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if(argc != 2){
        printf("Usage: ./recover IMAGE");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if(file == NULL){
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }
    unsigned char buffer[512];
    int ct_img = 0;

    FILE *output = NULL;

    char *filename = malloc(8 * sizeof(char));

    while (fread(buffer, sizeof(char), 512, file) == 512)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0)){
                sprintf(filename, "%03i.jpg", ct_img);
                output = fopen(filename, "w");
                ct_img++;
        }
        if(output != NULL){
            fwrite(buffer, sizeof(char), 512, output);
        }
    }
    free(filename);
    fclose(file);
    fclose(output);

    return 0;
}