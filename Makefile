CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Wconversion -Wshadow -Wcast-qual -Wstrict-prototypes -Wmissing-prototypes -Wwrite-strings  
objects = image.o test.o loadbmp.o savebmp.o algo.o 
outputs = gammatrans1.bmp gammatrans2.bmp invert.bmp invlogtrans.bmp logtrans.bmp threshold.bmp threshold2.bmp padding.bmp
	
ImageLib: $(objects)
	gcc -lm $(objects) -o test


image.o:
test.o: image.h bmp.h algo.h
loadbmp.o: image.h bmp.h
savebmp.o: bmp.h
algo.o: image.h


.PHONY: clean
clean:
	rm -f $(objects) $(outputs) test


