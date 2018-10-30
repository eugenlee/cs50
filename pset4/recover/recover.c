#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Only one raw image file input\n");
        return 1;
    }

    // store filename
    char *raw = argv[1];

    // open input file and check for error
    FILE *file = fopen(raw,"r");
    if (file == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", raw);
        return 2;
    }

    /* read memory card 512 bytes at a time to check if
    first four are jpeg, if not ignore and continue to next block
    once reach end, close it and start a new one until EOF */

    typedef uint8_t BYTE;
    BYTE buffer[512];
    int jpg_count = 0;
    char filename[8];
    FILE *img;
    int found = 0;

    // add some sort of loop
    while (fread(buffer, 1, 512, file) == 512)
    {
        // check to see if first four are new jpg file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 &&
            buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            found = 1;
            // if it is jpg
            // if a jpg is already open, ignored if it is first jpg found
            if (jpg_count > 0)
            {
                fclose(img);
            }
            // open next jpg file after closing previous one
            sprintf(filename, "%03i.jpg", jpg_count);
            img = fopen(filename, "w");
            fwrite(buffer, 1, 512, img);
            jpg_count++;
        }

        // else still 512 bytes but continuation of jpg
        else
        {
            if (found == 1)
            {
                fwrite(buffer, 1, 512, img);
            }
        }
    }
    // close files
    fclose(img);
    fclose(file);
    return 0;
}
