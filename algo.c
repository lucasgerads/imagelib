#include "algo.h"
#include <math.h>
#include <stdio.h>

void thresholding(int threshold, unsigned char* image, int imageSize){
    int n;
    for (n = 0; n < imageSize; n++){
        if (image[n] < threshold){
            image[n] = 0;
        }else {
            image[n] = 255;
        }
    }
}


void inverting(unsigned char* image, int imageSize){
    int n;
    for (n = 0; n < imageSize; n++){
        image[n] = 255 - image[n];
    }
}
 
void averaging(int neighborhoodSize, unsigned char* image, int width, int height){}

void padding(int paddingWidth, unsigned char* image, int width, int height){}


//logs are not correct
void logTransformation(int c, unsigned char* image, int imageSize){
    int n;
    double result;
    for (n = 0; n < imageSize; n++){ 
        result = c * log((double)image[n]/(double)c + 1);
        image[n] = (unsigned char) result;
    }
}

void inverseLogTransformation(int c, unsigned char* image, int imageSize){
   int n;
    double result;
    for (n = 0; n < imageSize; n++){
        result = c * (exp((double) image[n]/(double)c - 1));
        image[n] = (unsigned char) result;
    }
} 

void gammaTransformation(int gamma, int c, unsigned char* image, int imageSize){
    

}
