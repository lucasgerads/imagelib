#include "algo.h"
#include <math.h>
#include <stdio.h>


#define EULER 2.7182818284


void thresholding(int threshold, Image* image){
    unsigned int n;
    for (n = 0; n < image->size; n++){
        if (image->raw[n] < threshold){
            image->raw[n] = 0;
        }else {
            image->raw[n] = 255;
        }
    }
}


void inverting(Image* image){
    unsigned int n;
    for (n = 0; n < image->size; n++){
        image->raw[n] = 255 - image->raw[n];
    }
}
 
void averaging(int neighborhoodSize, unsigned char* image, int width, int height){}

void padding(int paddingWidth, unsigned char* image, int width, int height){}


//logs are not correct
void logTransformation(int c, unsigned char* image, unsigned int imageSize){
    unsigned int n;
    double result;
    double normalizedRange = (double) c;
    double normalizedImage;
    for (n = 0; n < imageSize; n++){ 
        normalizedImage = (double)image[n]/normalizedRange;
        result = normalizedRange * log((EULER-1)*normalizedImage + 1);
        //printf("image: %f result: %f\n",normalizedImage,result);
        image[n] = (unsigned char) result;
    }
}

void inverseLogTransformation(int c, unsigned char* image, unsigned int imageSize){
    unsigned int n;
    double normalizedRange = (double) c;
    double normalizedImage;
    double result;
    for (n = 0; n < imageSize; n++){
        normalizedImage = (double)image[n]/normalizedRange;
        result = normalizedRange * (exp(normalizedImage)-1)/EULER;
        image[n] = (unsigned char) result;
    }
} 

void gammaTransformation(double gammaConst, int c, unsigned char* image, unsigned int imageSize){
    unsigned int n;
    double normalizedRange = (double) c;
    double normalizedImage; 
    double result;
    for (n = 0; n < imageSize; n++){
        normalizedImage = (double) image[n]/normalizedRange;
        result = normalizedRange * pow(normalizedImage, gammaConst);
        image[n] = (unsigned char) result; 
    }
}




















