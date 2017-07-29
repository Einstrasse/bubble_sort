bubble: bubble.o lcgrand.o
	g++ -o bubble bubble.o lcgrand.o -std=c++11
bubble.o: bubble.cpp
	g++ -c -o bubble.o bubble.cpp -std=c++11
lcgrand.o: lcgrand.cpp
	g++ -c -o lcgrand.o lcgrand.cpp -std=c++11