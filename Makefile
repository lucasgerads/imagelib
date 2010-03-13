CC = gcc
CFLAGS = -Wall -W -Wconversion -Wshadow -Wcast-qual -Wwrite-strings  
objects = test.o loadbmp.o savebmp.o algo.o 
outputs = gammatrans1.bmp gammatrans2.bmp invert.bmp invlogtrans.bmp logtrans.bmp threshold.bmp
	
ChanelRouting: $(objects)
	gcc -lm $(objects) -o test

test.o: bmp.h algo.h
loadbmp.o: bmp.h
savebmp.o: bmp.h
algo.o: algo.h


.PHONY: clean
clean:
	rm -f $(objects) $(outputs) test


