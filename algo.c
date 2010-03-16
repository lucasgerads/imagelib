#include "algo.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "image.h"

#define EULER 2.7182818284


void pointProcessing(Image* image, void* data, unsigned char (*function)(unsigned char, void*)){
	unsigned n;
	for (n = 0; n < image->size; n++){
		image->raw[n] = (*function)(image->raw[n], data);
	}
}

void neighborhoodProcessing(Image* image, unsigned maskSize, unsigned char (*function)(SubImage*)){
	unsigned n,m;
	unsigned padSize;
	Image* paddedImage;		
	padSize = maskSize/2;	//this will round down
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


Histogram* createHistogram(Image* image){
	Histogram* newHistogram;
	newHistogram = (Histogram*)malloc(sizeof(Histogram));
	unsigned n;
	for (n = 0; n < image->size; n++){
		newHistogram->data[(int)image->raw[n]]++;
	}
	for (n = 0; n < 256; n++){
		newHistogram->normalizedData[n] = (double)newHistogram->data[n]/(double)image->size;
	}
	return newHistogram;
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

int compare (const void* a, const void* b){
	return (*(const int*)a - *(const int*)b);
}

unsigned char median(SubImage* image){
	unsigned x,y;
	int *pix = (int*)malloc(sizeof(int)*image->size);
	int n = 0;
	for (x = 0; x < image->width; x++){
		for (y = 0; y < image->height; y++){
			pix[n] = getSub(image, x, y);	
			n++;
		}
	}
	qsort(pix, image->size,sizeof(int), compare);
	unsigned char result = (unsigned char)pix[image->size/2 + 1];
	free(pix);
	return result; 
}

unsigned char maximum(SubImage* image){
	unsigned x,y;
	int max = 0;
	for (x = 0; x < image->width; x++){
		for (y = 0; y < image->height; y++){
			if (max < getSub(image, x, y)){
				max = getSub(image, x, y);		
			}
		}
	}
	return (unsigned char) max;
}


unsigned char threshold(unsigned char input, void* value){
	assert(value);	//check if pointer has at least some sort of value
	int thresholdValue = *(int *)value;
	if (input < thresholdValue){
		return 0;
	} else {
		return 255;
	}
}

unsigned char invert(unsigned char input, void* voidPtr){
	assert(!voidPtr);	//check if voidPtr is really NULL
	return (unsigned char)(255 - input);
}

unsigned char inverseLogTransformation(unsigned char input,void* voidPtr){
	assert(!voidPtr);	//check if voidPtr is really NULL
	double normalizedRange = 255.0;
	double normalizedImage;
	normalizedImage = (double)input/normalizedRange;
	return (unsigned char) (normalizedRange * (exp(normalizedImage)-1)/EULER);
}

unsigned char logTransformation(unsigned char input, void* voidPtr){
	assert(!voidPtr);	//check if voidPtr is really NULL
	double normalizedRange = 255.0;
	double normalizedImage;
	normalizedImage = (double)input/normalizedRange;
	return (unsigned char) (normalizedRange * log((EULER-1)*normalizedImage + 1));
}

unsigned char gammaTransformation(unsigned char input, void* value){	
	assert(value);	//check if pointer has at least some sort of value
	int gammaValue = *(int*)value;
	double normalizedRange = 255.0;
	double normalizedImage;
	normalizedImage = (double)input/normalizedRange;
	return (unsigned char)(normalizedRange * pow(normalizedImage, gammaValue));
}

unsigned char bitPlaneSlicing(unsigned char input, void* value){
	assert(value);	//check if pointer has at least some sort of value
	int planeValue = *(int*)value;
	return (unsigned char)(input & planeValue);
}





//logs are not correct



 























