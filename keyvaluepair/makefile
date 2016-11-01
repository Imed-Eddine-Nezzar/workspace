all: obj
	g++ -std=c++14 -Wall *.o -o keyvalpair.out

obj:
	g++ -std=c++14 -Wall *.cpp -c

.PHONY: clean

clean:
	- rm *.o
	- rm *.out
