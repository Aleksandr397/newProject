compr : main.o Programm.o Compress.o
	g++ main.o Programm.o Compress.o -o compr -Wall -pedantic --std=c++20

main.o : main.cpp
	g++ -c main.cpp

Programm.o : ./src/Programm.cpp
	g++ -c ./src/Programm.cpp

Compress.o : ./src/Compress.cpp
	g++ -c ./src/Compress.cpp

clean: 
	rm *.o