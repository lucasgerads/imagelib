#include "bmp.h"
#include <stdlib.h>
#include <stdio.h>


unsigned char *LoadBitmapFile(char *filename, Bmpfileinfo *bmpInfoHeader, Bmpfileheader *bmpFileHeader){
    int n;
    FILE *filePtr; //our file pointer
    Bmpfilemagic bmpmagic;
    unsigned char *rawImage;  //store image data
    //int imageIdx=0;  //image index counter
    //unsigned char tempRGB;  //our swap variable
    //open filename in read binary mode
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

      
    printf("fileptr: %p\n",filePtr);
    fseek(filePtr, bmpFileHeader->bmpdata_offset, SEEK_SET);
    
    printf("fileptr: %p\n",filePtr);
    rawImage = (unsigned char*)malloc(bmpInfoHeader->bmp_bytesz);
    fread(rawImage,1,bmpInfoHeader->bmp_bytesz, filePtr); 
    fclose(filePtr);
    printf("image address: %p\n", rawImage); 
    /*printf("first pixel = %2lX\n", (unsigned long)*rawImage);
    for (n = 0; n<3; n++){    
        printf("%d pixel = %2lX\n", n, (unsigned long)rawImage[n]);
    }
    printf("image address: %p\n", rawImage);*/
    return rawImage;
/*

    //move file point to the begging of bitmap data
    fseek(filePtr, bitmapFileHeader.bfOffBits, SEEK_SET);

    //allocate enough memory for the bitmap image data
    bitmapImage = (unsigned char*)malloc(bitmapInfoHeader->biSizeImage);

    //verify memory allocation
    if (!bitmapImage)
    {
        free(bitmapImage);
        fclose(filePtr);
        return NULL;
    }

    //read in the bitmap image data
    fread(bitmapImage,1, bitmapInfoHeader->biSizeImage,filePtr);

    //make sure bitmap image data was read
    if (bitmapImage == NULL)
    {
        fclose(filePtr);
        return NULL;
    }

    //swap the r and b values to get RGB (bitmap is BGR)
    for (imageIdx = 0;imageIdx < bitmapInfoHeader->biSizeImage;imageIdx+=3)
    {
        tempRGB = bitmapImage[imageIdx];
        bitmapImage[imageIdx] = bitmapImage[imageIdx + 2];
        bitmapImage[imageIdx + 2] = tempRGB;
    }

    //close file and return bitmap iamge data
    fclose(filePtr);
    return bitmapImage;*/

}

