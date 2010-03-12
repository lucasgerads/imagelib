#ifndef ALGO_H
#define ALFO_H


void thresholding(int threshold, unsigned char* image, int imageSize); 

void inverting(unsigned char* image, int imageSize);

void averaging(int neighborhoodSize, unsigned char* image, int width, int height);

void padding(int paddingWidth, unsigned char* image, int width, int height);

void logTransformation(int c, unsigned char* image, int imageSize);

void inverseLogTransformation(int c, unsigned char* image, int imageSize);

void gammaTransformation(int gamma, int c, unsigned char* image, int imageSize);

#endif

