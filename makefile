main: main.o lcgrand.o sorting.o
	g++ -o main main.o lcgrand.o sorting.o -std=c++11 -Wall
main.o: main.cpp
	g++ -c -o main.o main.cpp -std=c++11 -Wall
lcgrand.o: lcgrand.cpp
	g++ -c -o lcgrand.o lcgrand.cpp -std=c++11 -Wall
sorting.o: sorting.cpp
	g++ -c -o sorting.o sorting.cpp -std=c++11 -Wall

clean:
	rm *.o main