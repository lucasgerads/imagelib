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


int get(Image* image,unsigned x,unsigned y){
	if (x < image->width && y < image->height){	 
		return image->raw[x + image->width*y];
	} else {
		return -1;
	}
}

int set(Image* image, unsigned x, unsigned y, unsigned char value){
	if (x < image->width && y < image->height){	 
		return image->raw[x + image->width*y] = value;
	} else {
		return -1;
	}
}
	
Image* padding(unsigned padSize, Image* image){
	unsigned x,y;
	unsigned newHeight;
	unsigned newWidth;
	unsigned newSize; 
	unsigned char* newRawImage; 
	newHeight = image->height + 2*padSize;
	newWidth = image->width + 2*padSize;
	newSize = newHeight * newWidth;
	newRawImage = (unsigned char*)malloc(newSize);
	Image* newImage = (Image*)malloc(sizeof(Image));
	newImage->raw = newRawImage;
	newImage->size = newSize;
	newImage->width =	newWidth;
	newImage->height = newHeight; 
	for(y = 0; y < newImage->height; y++){
		for(x = 0; x < newImage->width; x++){
			if((x > padSize) && (y > padSize) && (x < newImage->width - padSize) && (y < newImage->height - padSize)){
				set(newImage, x, y, (unsigned char)get(image, x - padSize, y - padSize));
			} else{
				/*missing meaningful padding*/
				set(newImage, x, y, 0);
			}
		}
	}
	return newImage;	
}
