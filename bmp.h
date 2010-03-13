#ifndef BMP_H 
#define BMP_H

#include <stdint.h>
#include "image.h"


typedef struct tag_Bmpfilemagic{
    unsigned char magic[2];
}Bmpfilemagic;

typedef struct tag_Bmpfileheader
{
uint32_t filesz;  //specifies the size in bytes of the bitmap file
uint16_t creator1;  //reserved; must be 0
uint16_t creator2;  //reserved; must be 0
uint32_t bmpdata_offset;  //species the offset in bytes from the bitmapfileheader to the bitmap bits
}Bmpfileheader;

typedef struct tag_Bmpfileinfo
{
uint32_t header_sz;  //specifies the number of bytes required by the struct
uint32_t width;  //specifies width in pixels
uint32_t height;  //species height in pixels
uint16_t nplanes; //specifies the number of color planes, must be 1
uint16_t bitspp; //specifies the number of bit per pixel
uint32_t compress_type;//spcifies the type of compression
uint32_t bmp_bytesz;  //size of image in bytes
uint32_t hres;  //number of pixels per meter in x axis
uint32_t vres;  //number of pixels per meter in y axis
uint32_t ncolors;  //number of colors used by the bitmap which are defined in the colorpalet
uint32_t nimpcolors;  //number of colors that are important
}Bmpfileinfo;

Image* LoadBitmapFile(char *filename, Bmpfileinfo *bmpInfoHeader, Bmpfileheader *bmpFileHeader);
void SaveBitmapFile(char *filename , Bmpfileinfo *bmpInfoHeader, Bmpfileheader *bmpFileHeader, unsigned char* rawImage); 

#endif
