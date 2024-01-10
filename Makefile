all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b
test1: all
	bin/gauss dane/A1 dane/b1
test2: all
	bin/gauss dane/A2 dane/b2

