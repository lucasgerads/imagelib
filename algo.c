#include "algo.h"
#include <math.h>
#include <stdio.h>
#include "image.h"

#define EULER 2.7182818284


void pointProcessing(Image* image, Point* functionConst, unsigned char (*function)(unsigned char, Point*)){
	unsigned int n;
		for (n = 0; n < image->size; n++){
			image->raw[n] = (*function)(image->raw[n], functionConst);
		}
}



unsigned char threshold(unsigned char input, Point* functionConst){
	if (input < functionConst->threshold){
		return 0;
	} else {
		return 255;
	}
}

unsigned char invert(unsigned char input, Point* functionConst){
	return (unsigned char)(255 - input);
}

unsigned char inverseLogTransformation(unsigned char input, Point* functionConst){
	double normalizedRange = 255.0;
	double normalizedImage;
	normalizedImage = (double)input/normalizedRange;
	return (unsigned char) (normalizedRange * (exp(normalizedImage)-1)/EULER);
}

unsigned char logTransformation(unsigned char input, Point* functionConst){
	double normalizedRange = 255.0;
	double normalizedImage;
	normalizedImage = (double)input/normalizedRange;
	return (unsigned char) normalizedRange * log((EULER-1)*normalizedImage + 1);
}

unsigned char gammaTransformation(unsigned char input, Point* functionConst){
	double normalizedRange = 255.0;
	double normalizedImage;
	normalizedImage = (double)input/normalizedRange;
	return (unsigned char)(normalizedRange * pow(normalizedImage, functionConst->gamma));
}


void averaging(unsigned maskSize, Image* image){
	unsigned n,m;
	unsigned x,y;
	unsigned int padSize; 	//padding that will be added on all sides of the image
	Image* paddedImage;
	//int mask[] = (int*)malloc(sizeof(int)*maskSize*maskSize);
	unsigned sum;
	padSize =  maskSize/2 - 1;
	paddedImage = padding(padSize,image);
	for (m = 0; m < image->width; m++){
		for ( n = 0; n < image->height; n++){
			sum = 0;
			for(x = 0; x < maskSize; x++){
				for(y = 0; y < maskSize; y++){
					sum = sum + paddedImage->raw[(x+m)*paddedImage->height + (y + n)];
				}
			}
			sum = sum/(maskSize*maskSize);	
			image->raw[image->height*m + n] = (unsigned char)sum;
		}
	}
	release(paddedImage);	
}




//logs are not correct



 























