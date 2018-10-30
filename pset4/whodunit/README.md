# Questions

## What's `stdint.h`?

It declares sets of integer types with specified widths and their corresponding macros.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

To specify exactly how data will be interpreted especially across different platforms.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1, 4, 4, 2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The file type, which is BM in ASCII.

## What's the difference between `bfSize` and `biSize`?

The number of bytes of the bitmap file versus the number of bytes required by the structure.

## What does it mean if `biHeight` is negative?

The bitmap is a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If the file does not exist.

## Why is the third argument to `fread` always `1` in our code?

Number of elements to read which is to read through each structure one at a time.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

A value of 1.

## What does `fseek` do?

Changes the offset of the file pointer.

## What is `SEEK_CUR`?

To change the location of the file pointer from its current location.

## Whodunit?
It was Professor Plum with the candlestick in the library.

