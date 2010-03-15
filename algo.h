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
		



void averaging(unsigned mask, Image* image);


void pointProcessing(Image* image, void* constant, unsigned char (*function)(unsigned char, void*));

void neighborhoodProcessing(Image* image, unsigned maskSize, unsigned char (*function)(Image*));




/***************functions for point processing***************************************/
unsigned char threshold(unsigned char input, Point* functionConst);

unsigned char invert(unsigned char input, void* voidPtr);

unsigned char inverseLogTransformation(unsigned char input, void* voidPtr);

unsigned char logTransformation(unsigned char input, void* voidPtr);

unsigned char gammaTransformation(unsigned char input, Point* functionConst);
/***********************************************************************************/


/*************functions for neighborhood processing*********************************/
unsigned char average(Image* image);
/***********************************************************************************/

#endif

