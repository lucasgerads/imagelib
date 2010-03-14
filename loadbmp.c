#include "bmp.h"
#include <stdlib.h>
#include <stdio.h>


Image* LoadBitmapFile(char *filename, Bmpfileinfo *bmpInfoHeader, Bmpfileheader *bmpFileHeader){
    FILE *filePtr; 
    Bmpfilemagic bmpmagic;
    unsigned char *rawImage;  
	Image* image;

    filePtr = fopen(filename,"rb");
    if (filePtr == NULL){
        printf("file was not opened\n");
        return NULL;
    }
    fread(&bmpmagic,1,sizeof(Bmpfilemagic),filePtr);
    printf("file identification: %x%x\n", bmpmagic.magic[0], bmpmagic.magic[1]);

    if(bmpmagic.magic[0]!=0x42 && bmpmagic.magic[1] != 0x4d){
        printf("not BMP file\n");
        fclose(filePtr);
        return NULL;
    }

    fread(bmpFileHeader,1,sizeof(Bmpfileheader),filePtr);
    printf("filesize:\t%08lX\n", (unsigned long)bmpFileHeader->filesz);
    printf("creator1:\t%08lX\n", (unsigned long)bmpFileHeader->creator1);
    printf("creator2:\t%08lX\n", (unsigned long)bmpFileHeader->creator2);
    printf("data offset:\t%08lX\n", (unsigned long)bmpFileHeader->bmpdata_offset);

    fread(bmpInfoHeader, 1,sizeof(Bmpfileinfo),filePtr);
    printf("header size:\t%08lX\n", (unsigned long)bmpInfoHeader->header_sz); 
    printf("width:\t\t%08lX\n", (unsigned long)bmpInfoHeader->width);
    printf("height:\t\t%08lX\n", (unsigned long)bmpInfoHeader->height);
    printf("color planes:\t%08lX\n", (unsigned long)bmpInfoHeader->nplanes);
    printf("bits per pixel:\t%08lX\n", (unsigned long)bmpInfoHeader->bitspp);
    printf("compression:\t%08lX\n", (unsigned long)bmpInfoHeader->compress_type);
    printf("raw size:\t%08lX\n", (unsigned long)bmpInfoHeader->bmp_bytesz);
    printf("horizontal res:\t%08lX\n", (unsigned long)bmpInfoHeader->hres);
    printf("vertical res:\t%08lX\n", (unsigned long)bmpInfoHeader->vres);
    printf("number colors:\t%08lX\n", (unsigned long)bmpInfoHeader->ncolors);
    printf("imprtnt colors:\t%08lX\n", (unsigned long)bmpInfoHeader->nimpcolors);

      
    /*printf("fileptr: %p\n",filePtr);*/
    fseek(filePtr, (long int)bmpFileHeader->bmpdata_offset, SEEK_SET);
    
    /*printf("fileptr: %p\n",filePtr);*/
    rawImage = (unsigned char*)malloc(bmpInfoHeader->bmp_bytesz);
    fread(rawImage,1,bmpInfoHeader->bmp_bytesz, filePtr); 
    fclose(filePtr);
    printf("image address: %p\n", rawImage); 

	/*wrap raw image into a struct*/ 
	image = (Image*)malloc(sizeof(Image));
	image->raw = rawImage;
	image->width = bmpInfoHeader->width;
	image->height = bmpInfoHeader->height;
	image->size = bmpInfoHeader->bmp_bytesz;	
	    
    return image;

}

