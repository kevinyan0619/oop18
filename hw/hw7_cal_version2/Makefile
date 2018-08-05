all:	
	g++ -std=c++11 -c parser.cpp -o parser.o
	g++ -std=c++11 -c token.cpp -o token.o
	g++ -std=c++11 -c vars.cpp -o vars.o
	g++ -std=c++11 -c main.cpp -o main.o
	g++ -std=c++11 -o calc parser.o token.o vars.o main.o

clean:
	rm -rf *.o
	rm -rf calc
