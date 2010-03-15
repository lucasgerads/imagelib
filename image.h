#ifndef IMAGE_H
#define IMAGE_H

typedef struct tag_Image{
	unsigned int size;
	unsigned int width;
	unsigned int height;
	unsigned char* raw;
}Image; 

typedef struct tag_subImage{
	unsigned int size;
	unsigned int width;
	unsigned int height;
	unsigned char* raw;	
	Image* parent;
} SubImage;


Image* create(unsigned char* raw, unsigned int size, unsigned int width, unsigned int height);

void release(Image* image);

int get(Image* image, unsigned x, unsigned y);

int set(Image* image, unsigned x, unsigned y, unsigned char value);

Image* padding(unsigned padSize, Image* image);

unsigned char* getAddress(Image* image,unsigned x,unsigned y);

int getSub(SubImage* image, unsigned x, unsigned y);
#endif
