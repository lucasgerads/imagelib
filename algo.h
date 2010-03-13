#ifndef ALGO_H
#define ALFO_H
#include "image.h"

void thresholding(int threshold, Image* image); 

void inverting(Image* image);

void averaging(int neighborhoodSize, unsigned char* image, int width, int height);

void padding(int paddingWidth, unsigned char* image, int width, int height);

void logTransformation(int c, unsigned char* image, unsigned int imageSize);

void inverseLogTransformation(int c, unsigned char* image, unsigned int imageSize);

void gammaTransformation(double gamma, int c, unsigned char* image, unsigned int imageSize);

#endif

