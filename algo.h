#ifndef ALGO_H
#define ALFO_H
#include "image.h"

void thresholding(int threshold, Image* image); 

void inverting(Image* image);

void averaging(int neighborhoodSize, unsigned char* image, int width, int height);

void padding(int paddingWidth, unsigned char* image, int width, int height);

void logTransformation(Image* image);

void inverseLogTransformation(Image* image);

void gammaTransformation(double gammaConst, Image* image);

#endif

