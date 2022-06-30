CC=g++
CFLAGS=-c -Wall

target: first

first: AVL.o TreeNode.o main.o
	$(CC) AVL.o TreeNode.o main.o -o avlfreq

AVL.o: AVL.cpp
	$(CC) $(CFLAGS) AVL.cpp

TreeNode.o: TreeNode.cpp
	$(CC) $(CFLAGS) TreeNode.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
clean:
	rm *o avlfreq