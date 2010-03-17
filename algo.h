#ifndef ALGO_H
#define ALFO_H
#include "image.h"
/*
typedef struct tag_Point{
	unsigned char threshold;
	double gamma;
	unsigned plane;
} Point;*/

typedef struct tag_Mask{
	int dummy;
}Mask;
		
typedef struct tag_Histogram{
	int data[256];
	double normalizedData[256];
	double transformation[256];	
	int lookUp[256];	
} Histogram;


void averaging(unsigned mask, Image* image);


void pointProcessing(Image* image, void* constant, unsigned char (*function)(unsigned char, void*));

void neighborhoodProcessing(Image* image, unsigned maskSize, unsigned char (*function)(SubImage*));

Histogram* createHistogram(Image* image);

void equalizationLookUp(Histogram* histo); 


/***************functions for point processing***************************************/
unsigned char threshold(unsigned char input, void* value);

unsigned char invert(unsigned char input, void* voidPtr);

unsigned char inverseLogTransformation(unsigned char input, void* voidPtr);

unsigned char logTransformation(unsigned char input, void* voidPtr);

unsigned char gammaTransformation(unsigned char input, void* value);

unsigned char bitPlaneSlicing(unsigned char input, void* value);

unsigned char useLookUp(unsigned char input, void* lookUpTable);
/***********************************************************************************/


/*************functions for neighborhood processing*********************************/
unsigned char average(SubImage* image);

unsigned char median(SubImage* image);

unsigned char maximum(SubImage* image);
/***********************************************************************************/

/***********helper functions********************************************************/
int compare (const void* a, const void* b);
/***********************************************************************************/

#endif

