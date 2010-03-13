#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "algo.h"

int
main(){
    Bmpfileinfo bmpInfoHeader;
    
    Bmpfileheader bmpFileHeader; //our bitmap file header
    unsigned char *bitmapData;
    
    char filename[] = "lena512.bmp";
	char filethreshold[] = "threshold.bmp";
	char fileinvert[] = "invert.bmp";
	char filelog[] = "logtrans.bmp";
	char fileinvlog[] = "invlogtrans.bmp";
	char filegamma1[] = "gammatrans1.bmp";
	char filegamma2[] = "gammatrans2.bmp";

    bitmapData = LoadBitmapFile(filename ,&bmpInfoHeader, &bmpFileHeader); 
    thresholding(128, bitmapData, bmpInfoHeader.bmp_bytesz);  
    SaveBitmapFile(filethreshold, &bmpInfoHeader, &bmpFileHeader, bitmapData);
    free(bitmapData);

    bitmapData = LoadBitmapFile(filename,&bmpInfoHeader, &bmpFileHeader); 
    inverting(bitmapData, bmpInfoHeader.bmp_bytesz);  
    SaveBitmapFile(fileinvert, &bmpInfoHeader, &bmpFileHeader, bitmapData);
    free(bitmapData);

    bitmapData = LoadBitmapFile(filename, &bmpInfoHeader, &bmpFileHeader); 
    logTransformation(255, bitmapData, bmpInfoHeader.bmp_bytesz);  
    SaveBitmapFile(filelog, &bmpInfoHeader, &bmpFileHeader, bitmapData);
    free(bitmapData); 

    bitmapData = LoadBitmapFile(filename, &bmpInfoHeader, &bmpFileHeader); 
    inverseLogTransformation(255, bitmapData, bmpInfoHeader.bmp_bytesz);  
    SaveBitmapFile(fileinvlog, &bmpInfoHeader, &bmpFileHeader, bitmapData);
    free(bitmapData);


    bitmapData = LoadBitmapFile(filename,&bmpInfoHeader, &bmpFileHeader); 
    gammaTransformation(10, 255, bitmapData, bmpInfoHeader.bmp_bytesz);  
    SaveBitmapFile(filegamma1, &bmpInfoHeader, &bmpFileHeader, bitmapData);
    free(bitmapData);

    bitmapData = LoadBitmapFile(filename, &bmpInfoHeader, &bmpFileHeader); 
    gammaTransformation(0.1, 255, bitmapData, bmpInfoHeader.bmp_bytesz);  
    SaveBitmapFile(filegamma2, &bmpInfoHeader, &bmpFileHeader, bitmapData);
    free(bitmapData);
    /*
    bitmapData = (unsigned char*) LoadBitmapFile("lena512.bmp", &bmpInfoHeader, & bmpFileHeader);
    height = bmpInfoHeader.height;
    width = bmpInfoHeader.width;
    outBitmapData = (unsigned char*)malloc(bmpInfoHeader.bmp_bytesz); 
    mask = (unsigned char*)malloc(bmpInfoHeader.bmp_bytesz);
    enhanced = (unsigned char*)malloc(bmpInfoHeader.bmp_bytesz);
    for (m = 1; m < height - 1; m++){
        for (n = 1; n < width - 1; n++){
           sum =    bitmapData[height*m +  n]      + bitmapData[height*(m+1)+(n-1)] + bitmapData[height*(m+1)+(n)]
                  + bitmapData[height*(m+1)+(n+1)] + bitmapData[height*(m)+(n-1)]   + bitmapData[height*(m+1)+(n+1)] 
                  + bitmapData[height*(m-1)+(n-1)] + bitmapData[height*(m-1)+(n)]   + bitmapData[height*(m-1)+(n+1)];
           outBitmapData[height*m +  n] = sum/9;
        }
    }
    SaveBitmapFile("output3.bmp", &bmpInfoHeader, &bmpFileHeader, outBitmapData);
    
    for (n = 0; n < bmpInfoHeader.bmp_bytesz; n++){
        mask[n] = bitmapData[n] - outBitmapData[n];
    }
    SaveBitmapFile("mask.bmp", &bmpInfoHeader, &bmpFileHeader, mask);

    for (n = 0; n < bmpInfoHeader.bmp_bytesz; n++){
        enhanced[n] = mask[n] + bitmapData[n];
    }
    SaveBitmapFile("enhance.bmp", &bmpInfoHeader, &bmpFileHeader, enhanced);

    free(bitmapData);
    free(outBitmapData);
    free(mask);
    free(enhanced);
    */
    return 0;
 }
