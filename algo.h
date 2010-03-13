#ifndef ALGO_H
#define ALFO_H
#include "image.h"

void thresholding(int threshold, Image* image); 

void inverting(Image* image);

void averaging(unsigned mask, Image* image);

/*void padding(int padSize, Image* image);*/

void logTransformation(Image* image);

void inverseLogTransformation(Image* image);

void gammaTransformation(double gammaConst, Image* image);

#endif

