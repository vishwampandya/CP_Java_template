
CC=gcc

.PHONY: all

all: comp detect.out

#mystring.o: mystring.c
#	$(CC) -c -fPIC -o $@ $<
	
#mystring.so: mystring.o
#	$(CC) -shared -o $@ $<

comp.o: comp.c
	$(CC) -c -o $@ $<

comp: comp.o
	$(CC) -o $@ $^
	
detect.out: detect.c
	$(CC) -o $@ $^
	
.PHONY: clean

clean: 
	rm -f *.o 
	rm -f *.out 
	rm -f *.so
