#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open\n");
        return 1;
    }

    FILE *outptr = NULL;

    BYTE buffer[512];

    int jpeg = 0;

    char name[8] = {0};

    while (fread(buffer, sizeof(BYTE) * 512, 1, inptr) == 1)
    {
        if ((buffer[0] == 0xFF) && (buffer[1] == 0xD8) && (buffer[2] == 0xFF) && (buffer[3] == 0xE0))
        {
            if (outptr != NULL)
            {
                fclose(outptr);
            }

            sprintf(name, "%03d.jpg", jpeg++);
            outptr = fopen(name, "w");
        }

        if (outptr != 0)
        {
            fwrite(buffer, sizeof(BYTE) * 512, 1, outptr);
        }
    }

    if (outptr != 0)
    {
        fclose(outptr);
    }

    fclose(inptr);

    return 0;
}