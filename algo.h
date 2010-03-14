#ifndef ALGO_H
#define ALFO_H
#include "image.h"

typedef struct tag_Point{
	unsigned char threshold;
	double gamma;
} Point;

typedef struct tag_Mask{
	int dummy;
}Mask;
		

void thresholding(int threshold, Image* image); 

void inverting(Image* image);

void averaging(unsigned mask, Image* image);

/*void padding(int padSize, Image* image);*/

void logTransformation(Image* image);

void inverseLogTransformation(Image* image);

void gammaTransformation(double gammaConst, Image* image);

void pointProcessing(Image* image, Point* functionConst, unsigned char (*function)(unsigned char, Point*));

void neighborhoodProcessing(Image* image, unsigned char (*function)(Image*, Mask*));

unsigned char threshold(unsigned char input, Point* functionConst);

#endif

