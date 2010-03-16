#include "bmp.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "image.h"


Image* LoadBitmapFile(char *filename, Bmpfileinfo *bmpInfoHeader, Bmpfileheader *bmpFileHeader){
    FILE *filePtr; 
	size_t readData;
    Bmpfilemagic bmpmagic;
    unsigned char *rawImage;  
	Image* image;

    filePtr = fopen(filename,"rb");
    if (filePtr == NULL){
        printf("file was not opened\n");
        return NULL;
    }
    readData = fread(&bmpmagic,1,sizeof(Bmpfilemagic),filePtr);
	assert(readData == sizeof(Bmpfilemagic));

    if(bmpmagic.magic[0]!=0x42 && bmpmagic.magic[1] != 0x4d){
        printf("not BMP file\n");
        fclose(filePtr);
        return NULL;
    }

    readData = fread(bmpFileHeader,1,sizeof(Bmpfileheader),filePtr);
	assert(readData == sizeof(Bmpfileheader));
    readData = fread(bmpInfoHeader, 1,sizeof(Bmpfileinfo),filePtr);
	assert(readData == sizeof(Bmpfileinfo));
     
    fseek(filePtr, (long int)bmpFileHeader->bmpdata_offset, SEEK_SET);
    
    rawImage = (unsigned char*)malloc(bmpInfoHeader->bmp_bytesz);
    readData = fread(rawImage,1,bmpInfoHeader->bmp_bytesz, filePtr); 
	assert(readData == bmpInfoHeader->bmp_bytesz);
    fclose(filePtr);


	/*wrap raw image into a struct*/ 
	image = (Image*)malloc(sizeof(Image));
	image->raw = rawImage;
	image->width = bmpInfoHeader->width;
	image->height = bmpInfoHeader->height;
	image->size = bmpInfoHeader->bmp_bytesz;	
	    
    return image;

}

