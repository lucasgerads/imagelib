#include "image.h"
#include "stdlib.h"

 
Image* create(unsigned char* raw, unsigned int size, unsigned int width, unsigned int height){
	Image* newImage;
	newImage = (Image*)malloc(sizeof(Image));
	newImage->raw = raw;
	newImage->size = size;
	newImage->width = width;
	newImage->height = height;
	return newImage;
}
		


void release(Image* image){
	free(image->raw);
	free(image);
}
