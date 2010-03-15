#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "algo.h"
#include "image.h"

int main(void);

int
main(){
    Bmpfileinfo bmpInfoHeader; 
    Bmpfileheader bmpFileHeader; 
    Image* image;
	Image* newImage;
    
    char filename[] = "lena512.bmp";
	
	char filethreshold[] = "threshold.bmp";
	Point mypoint;
	mypoint.threshold = 128;	
	image = LoadBitmapFile(filename, &bmpInfoHeader, &bmpFileHeader); 
	pointProcessing(image, &mypoint, &threshold);
	SaveBitmapFile(filethreshold, &bmpInfoHeader, &bmpFileHeader, image->raw);
	release(image);

	char fileinvert[] = "invert.bmp";
	image = LoadBitmapFile(filename, &bmpInfoHeader, &bmpFileHeader); 
	pointProcessing(image,NULL,&invert);
	SaveBitmapFile(fileinvert, &bmpInfoHeader, &bmpFileHeader, image->raw);
	release(image);
	
	char filelog[] = "logtrans.bmp";
    image = LoadBitmapFile(filename, &bmpInfoHeader, &bmpFileHeader); 
	pointProcessing(image, NULL, &logTransformation);
    SaveBitmapFile(filelog, &bmpInfoHeader, &bmpFileHeader, image->raw);
    release(image); 

	char fileinvlog[] = "invlogtrans.bmp";
    image = LoadBitmapFile(filename, &bmpInfoHeader, &bmpFileHeader); 
	pointProcessing(image,NULL, &inverseLogTransformation);
    SaveBitmapFile(fileinvlog, &bmpInfoHeader, &bmpFileHeader, image->raw);
    release(image);

	char filegamma[] = "gammatrans1.bmp";
    image = LoadBitmapFile(filename,&bmpInfoHeader, &bmpFileHeader); 
	mypoint.gamma = 10;
	pointProcessing(image, &mypoint, &gammaTransformation); 
    SaveBitmapFile(filegamma, &bmpInfoHeader, &bmpFileHeader, image->raw);
    release(image);

	
	/*This is just for testing! padding is only supposed to be called internally*/
	char filepadding[] = "padding.bmp";
	image = LoadBitmapFile(filename, &bmpInfoHeader, &bmpFileHeader); 
    newImage = padding(20, image);  
	bmpFileHeader.filesz = bmpFileHeader.bmpdata_offset + newImage->size;
	bmpInfoHeader.width = newImage->width;
	bmpInfoHeader.height = newImage->height;
	bmpInfoHeader.bmp_bytesz = newImage->size;		
    SaveBitmapFile(filepadding, &bmpInfoHeader, &bmpFileHeader, newImage->raw);
	release(newImage);
    release(image);
	
	
	char fileaverage1[]= "average1.bmp";
	image = LoadBitmapFile(filename, &bmpInfoHeader, &bmpFileHeader); 
	neighborhoodProcessing(image, 5, &average);
	SaveBitmapFile(fileaverage1, &bmpInfoHeader, &bmpFileHeader, image->raw);
	release(image);

	char fileaverage2[]= "average2.bmp";
	image = LoadBitmapFile(filename, &bmpInfoHeader, &bmpFileHeader); 
	neighborhoodProcessing(image, 10, &average);
	SaveBitmapFile(fileaverage2, &bmpInfoHeader, &bmpFileHeader, image->raw);
	release(image);

	char fileaverage3[]= "average3.bmp";
	image = LoadBitmapFile(filename, &bmpInfoHeader, &bmpFileHeader); 
	neighborhoodProcessing(image, 15, &average);
	SaveBitmapFile(fileaverage3, &bmpInfoHeader, &bmpFileHeader, image->raw);
	release(image);
	

	/*
	image = LoadBitmapFile(filename, &bmpInfoHeader, &bmpFileHeader); 
	averaging(13, image);
	SaveBitmapFile(fileaverage2, &bmpInfoHeader, &bmpFileHeader, image->raw);
	release(image);

	image = LoadBitmapFile(filename, &bmpInfoHeader, &bmpFileHeader); 
	averaging(19, image);
	SaveBitmapFile(fileaverage3, &bmpInfoHeader, &bmpFileHeader, image->raw);
	release(image);
	*/	


			
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
