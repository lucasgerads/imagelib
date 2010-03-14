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



void pointProcessing(Image* image, Point* functionConst, unsigned char (*function)(unsigned char, Point*));

void neighborhoodProcessing(Image* image, unsigned char (*function)(Image*, Mask*));




/***************functions for point processing***************************************/
unsigned char threshold(unsigned char input, Point* functionConst);

unsigned char invert(unsigned char input, Point* functionConst);

unsigned char inverseLogTransformation(unsigned char input, Point* functionConst);

unsigned char logTransformation(unsigned char input, Point* functionConst);

unsigned char gammaTransformation(unsigned char input, Point* functionConst);
/***********************************************************************************/

#endif

