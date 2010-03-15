#include "algo.h"
#include <math.h>
#include <stdio.h>
#include "image.h"

#define EULER 2.7182818284


void pointProcessing(Image* image, void* constant, unsigned char (*function)(unsigned char, void*)){
	unsigned n;
	for (n = 0; n < image->size; n++){
		image->raw[n] = (*function)(image->raw[n], constant);
	}
}

void neighborhoodProcessing(Image* image, unsigned maskSize, unsigned char (*function)(SubImage*)){
	unsigned n,m;
	unsigned padSize;
	Image* paddedImage;		
	padSize = maskSize/2 - 1;
	paddedImage = padding(padSize,image);
	SubImage subImage;
	subImage.width = maskSize;
	subImage.height = maskSize;
	subImage.size = maskSize * maskSize;
	subImage.parent = paddedImage;
	for (m = 0; m < image->width; m++){
		for (n = 0; n < image->height; n++){
			subImage.raw = getAddress(paddedImage, m, n); 
			unsigned char newValue = (*function)(&subImage);
			set(image, m, n, newValue);
		}
	}	
	release(paddedImage);
}

unsigned char average(SubImage* image){
	unsigned x,y;
	int sum = 0;
	for (x = 0; x < image->width; x++){
		for (y = 0; y < image->height; y++){
			sum = sum + getSub(image, x, y);	
		}
	}
	sum = sum/(int)(image->size);
	return (unsigned char)sum;	
}

/*
void average(Image* image){
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
}*/


unsigned char threshold(unsigned char input, Point* constant){
	if (input < constant->threshold){
		return 0;
	} else {
		return 255;
	}
}

unsigned char invert(unsigned char input, void* voidPtr){
	return (unsigned char)(255 - input);
}

unsigned char inverseLogTransformation(unsigned char input,void* voidPtr){
	double normalizedRange = 255.0;
	double normalizedImage;
	normalizedImage = (double)input/normalizedRange;
	return (unsigned char) (normalizedRange * (exp(normalizedImage)-1)/EULER);
}

unsigned char logTransformation(unsigned char input, void* voidPtr){
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







//logs are not correct



 























