#include "algo.h"
#include <math.h>
#include <stdio.h>


#define EULER 2.7182818284


void thresholding(int threshold, Image* image){
    unsigned int n;
    for (n = 0; n < image->size; n++){
        if (image->raw[n] < threshold){
            image->raw[n] = 0;
        }else {
            image->raw[n] = 255;
        }
    }
}


void inverting(Image* image){
    unsigned int n;
    for (n = 0; n < image->size; n++){
        image->raw[n] = (unsigned char) (255 - image->raw[n]);
    }
}
 
/*
void averaging(unsigned maskSize, Image* image){
	unsigned int n,m;
	int x,y;
	unsigned int padSize; 	//padding that will be added on all sides of the image
	Image* paddedImage;
	int mask[] = (int*)malloc(sizeof(int)*maskSize*maskSize);
	int sum;
	padSize = = mask/2 - 1;
	paddedImage = padding(image, padSize);
	for (m = 0; m < image->width; m++){
		for ( n = 0; n < image->height; n++){
			sum = 0;
			for(x = 0; x < maskSize; x++){
				for(y = 0; y < maskSize; y++){
					sum += paddedImage[(x+m)*paddedImage->height + (y + n)];
				}
			}
			image->raw[image->height*m + n];
		}
	}
	release	

}
*/



//logs are not correct
void logTransformation(Image* image){
    unsigned int n;
    double result;
    double normalizedRange = 255.0;
    double normalizedImage;
    for (n = 0; n < image->size; n++){ 
        normalizedImage = (double)image->raw[n]/normalizedRange;
        result = normalizedRange * log((EULER-1)*normalizedImage + 1);
        //printf("image: %f result: %f\n",normalizedImage,result);
        image->raw[n] = (unsigned char) result;
    }
}


void inverseLogTransformation(Image* image){
    unsigned int n;
    double normalizedRange = 255.0;
    double normalizedImage;
    double result;
    for (n = 0; n < image->size; n++){
        normalizedImage = (double)image->raw[n]/normalizedRange;
        result = normalizedRange * (exp(normalizedImage)-1)/EULER;
        image->raw[n] = (unsigned char) result;
    }
} 


void gammaTransformation(double gammaConst, Image* image){
    unsigned int n;
    double normalizedRange = 255.0;
    double normalizedImage; 
    double result;
    for (n = 0; n < image->size; n++){
        normalizedImage = (double) image->raw[n]/normalizedRange;
        result = normalizedRange * pow(normalizedImage, gammaConst);
        image->raw[n] = (unsigned char) result; 
    }
}




















