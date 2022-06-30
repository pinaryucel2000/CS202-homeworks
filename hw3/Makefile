CC=g++
CFLAGS=-c -Wall

target: first

first: heapsort.o heap.o
	$(CC) heapsort.o heap.o -o heapsort

heapsort.o: heapsort.cpp
	$(CC) $(CFLAGS) heapsort.cpp

heap.o: heap.cpp
	$(CC) $(CFLAGS) heap.cpp
clean:
	rm *o heapsort