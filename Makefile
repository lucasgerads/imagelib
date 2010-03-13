CC = gcc
CFLAGS = -Wall -W -Wconversion -Wshadow -Wcast-qual -Wwrite-strings  
objects = image.o test.o loadbmp.o savebmp.o algo.o 
outputs = gammatrans1.bmp gammatrans2.bmp invert.bmp invlogtrans.bmp logtrans.bmp threshold.bmp
	
ImageLib: $(objects)
	gcc -lm $(objects) -o test

test.o: bmp.h algo.h
loadbmp.o: bmp.h
savebmp.o: bmp.h
algo.o: algo.h
image.o:


.PHONY: clean
clean:
	rm -f $(objects) $(outputs) test


