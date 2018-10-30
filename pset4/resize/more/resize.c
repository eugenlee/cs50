// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: n infile outfile\n");
        return 1;
    }

    // store n
    float f = atof(argv[1]);
    //float f;
    //sscanf(argv[1], " %f", &f);

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // the first (n) must be a positive integer less than or equal to 100
    if (f < 0.0 || f > 100.0)
    {
        fprintf(stderr, "n must be a pos integer less than or equal to 100\n");
        return 1;
    }

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 1;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 1;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 1;
    }

    // old padding
    int old_padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // old width & old height
    int old_width = bi.biWidth;
    int old_height = bi.biHeight;
    int oldwidth = bi.biWidth;

    // change bi.biWidth & bi.biHeight
    bi.biWidth *= f;
    bi.biHeight *= f;

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // change bi.biSizeImage
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth)
                        + padding) * abs(bi.biHeight);

    // change bf.bfSize
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER)
                    + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // change height and counter if f < 1
    if (f < 1)
    {
        old_height *= f;
        old_width *= f;
    }

    // iterate over rows in scanline
    for (int j = 0; j < abs(old_height); j++)
    {
        // temporary storage
        RGBTRIPLE triple;
        RGBTRIPLE curry[bi.biWidth];
        int m = 0;

        // iterate over pixels in scanline
        for (int o = 0; o < old_width; o++)
        {
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // if f is less than 1, only print pixels to set length of new line
            if (f < 1)
            {
                curry[o] = triple;
                fseek(inptr, sizeof(RGBTRIPLE), SEEK_CUR);
            }
            else
            {
                // iterate for width into array
                for (int g = 0; g < f; g++)
                {
                    curry[m + g] = triple;
                }
            }
            // move pixel line
            if (f >= 1)
            {
                m += f;
            }
        }

        // ADD SOMETHING HERE TO GET TO END OF LINE
        if (f < 1)
        {
            fseek(inptr, 2 * old_padding + oldwidth * sizeof(RGBTRIPLE), SEEK_CUR);
        }

        // iterate for height into output and account for padding
        if (f < 1)
        {
            fwrite(&curry, sizeof(curry), 1, outptr);

            //
            for (int k = 0; k < padding; k++)
            {
                fputc(0x00, outptr);
            }
        }
        else
        {
            for (int l = 0; l < f; l++)
            {
                // write RGB triple to outfile
                fwrite(&curry, sizeof(curry), 1, outptr);

                //
                for (int k = 0; k < padding; k++)
                {
                    fputc(0x00, outptr);
                }
            }
            fseek(inptr, old_padding, SEEK_CUR);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
