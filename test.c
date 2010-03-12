#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "algo.h"

int
main(){
    Bmpfileinfo bmpInfoHeader;
    
    Bmpfileheader bmpFileHeader; //our bitmap file header
    unsigned char *bitmapData;
    unsigned char *outBitmapData;
    unsigned char *mask;
    unsigned char *enhanced;
    int n;
    int m;
    int sum;
    int height, width;

    bitmapData = (unsigned char*) LoadBitmapFile("lena512.bmp",&bmpInfoHeader, &bmpFileHeader); 
    thresholding(128, bitmapData, bmpInfoHeader.bmp_bytesz);  
    SaveBitmapFile("threshold.bmp", &bmpInfoHeader, &bmpFileHeader, bitmapData);
    free(bitmapData);

    bitmapData = (unsigned char*) LoadBitmapFile("lena512.bmp",&bmpInfoHeader, &bmpFileHeader); 
    inverting(bitmapData, bmpInfoHeader.bmp_bytesz);  
    SaveBitmapFile("invert.bmp", &bmpInfoHeader, &bmpFileHeader, bitmapData);
    free(bitmapData);

    bitmapData = (unsigned char*) LoadBitmapFile("lena512.bmp",&bmpInfoHeader, &bmpFileHeader); 
    logTransformation(255, bitmapData, bmpInfoHeader.bmp_bytesz);  
    SaveBitmapFile("logtrans.bmp", &bmpInfoHeader, &bmpFileHeader, bitmapData);
    free(bitmapData); 

    bitmapData = (unsigned char*) LoadBitmapFile("lena512.bmp",&bmpInfoHeader, &bmpFileHeader); 
    inverseLogTransformation(255, bitmapData, bmpInfoHeader.bmp_bytesz);  
    SaveBitmapFile("invlogtrans.bmp", &bmpInfoHeader, &bmpFileHeader, bitmapData);
    free(bitmapData);


    bitmapData = (unsigned char*) LoadBitmapFile("lena512.bmp",&bmpInfoHeader, &bmpFileHeader); 
    gammaTransformation(10, 255, bitmapData, bmpInfoHeader.bmp_bytesz);  
    SaveBitmapFile("gammatrans1.bmp", &bmpInfoHeader, &bmpFileHeader, bitmapData);
    free(bitmapData);

    bitmapData = (unsigned char*) LoadBitmapFile("lena512.bmp",&bmpInfoHeader, &bmpFileHeader); 
    gammaTransformation(0.1, 255, bitmapData, bmpInfoHeader.bmp_bytesz);  
    SaveBitmapFile("gammatrans2.bmp", &bmpInfoHeader, &bmpFileHeader, bitmapData);
    free(bitmapData);
    /*bitmapData = (unsigned char*) LoadBitmapFile("lena512.bmp", &bmpInfoHeader, &bmpFileHeader);
    for (n = 0; n < bmpInfoHeader.bmp_bytesz; n++){
        bitmapData[n] = 255 - bitmapData[n];
    }
    SaveBitmapFile("output2.bmp", &bmpInfoHeader, &bmpFileHeader, bitmapData);
    free(bitmapData);


    

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
