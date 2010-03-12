CC = gcc
CFLAGS = -Wall 
objects = test.o loadbmp.o savebmp.o algo.o 
	
ChanelRouting: $(objects)
	gcc $(objects) -o test

test.o: bmp.h algo.h
loadbmp.o: bmp.h
savebmp.o: bmp.h
algo.o: algo.h


.PHONY: clean
clean:
	rm -f $(objects) test


