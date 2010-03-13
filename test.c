#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "algo.h"
#include "image.h"

int
main(){
    Bmpfileinfo bmpInfoHeader;
    
    Bmpfileheader bmpFileHeader; //our bitmap file header
    Image* image;
    
    char filename[] = "lena512.bmp";
	char filethreshold[] = "threshold.bmp";
	char fileinvert[] = "invert.bmp";
	char filelog[] = "logtrans.bmp";
	char fileinvlog[] = "invlogtrans.bmp";
	char filegamma1[] = "gammatrans1.bmp";
	char filegamma2[] = "gammatrans2.bmp";

    image = LoadBitmapFile(filename ,&bmpInfoHeader, &bmpFileHeader); 
    thresholding(128, image);  
    SaveBitmapFile(filethreshold, &bmpInfoHeader, &bmpFileHeader, image->raw);
    release(image);

    image = LoadBitmapFile(filename,&bmpInfoHeader, &bmpFileHeader); 
    inverting(image);  
    SaveBitmapFile(fileinvert, &bmpInfoHeader, &bmpFileHeader, image->raw);
    release(image);

	
    image = LoadBitmapFile(filename, &bmpInfoHeader, &bmpFileHeader); 
    logTransformation(image);  
    SaveBitmapFile(filelog, &bmpInfoHeader, &bmpFileHeader, image->raw);
    release(image); 

    image = LoadBitmapFile(filename, &bmpInfoHeader, &bmpFileHeader); 
    inverseLogTransformation(image);  
    SaveBitmapFile(fileinvlog, &bmpInfoHeader, &bmpFileHeader, image->raw);
    release(image);


    image = LoadBitmapFile(filename,&bmpInfoHeader, &bmpFileHeader); 
    gammaTransformation(10, image);  
    SaveBitmapFile(filegamma1, &bmpInfoHeader, &bmpFileHeader, image->raw);
    release(image);

    image = LoadBitmapFile(filename, &bmpInfoHeader, &bmpFileHeader); 
    gammaTransformation(0.1, image);  
    SaveBitmapFile(filegamma2, &bmpInfoHeader, &bmpFileHeader, image->raw);
    release(image);

	
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
