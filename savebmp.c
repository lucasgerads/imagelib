#include "bmp.h"
#include <stdio.h>


void SaveBitmapFile(char *filename, Bmpfileinfo *bmpInfoHeader, Bmpfileheader *bmpFileHeader, unsigned char* rawImage){
    FILE *filePtr;
    int n;
    unsigned char empty = 0; 
    filePtr = fopen(filename, "wb");
    /*printf("fileptr: %p\n",filePtr);*/
    //printf("Offset: %x\n", bmpFileHeader->bmpdata_offset);
    //filePtr = filePtr - bmpFileHeader->bmpdata_offset; 
    

    char bmpMagic[] = { 'B' , 'M'};
    fwrite(bmpMagic, 1, sizeof(bmpMagic), filePtr); 
    fwrite(bmpFileHeader, 1, sizeof(Bmpfileheader),filePtr);
    fwrite(bmpInfoHeader, 1, sizeof(Bmpfileinfo), filePtr); 
    for (n = 0; n < 256; n++){
        fwrite(&n, 1, sizeof(char),filePtr); 
        fwrite(&n, 1, sizeof(char),filePtr);
        fwrite(&n, 1, sizeof(char),filePtr);
        fwrite(&empty, 1, 1, filePtr);
    } 
    if (!fseek(filePtr, (long int)bmpFileHeader->bmpdata_offset, SEEK_SET)){
    fwrite(rawImage, 1, bmpInfoHeader->bmp_bytesz, filePtr);
    }
    fclose(filePtr);
}
       
