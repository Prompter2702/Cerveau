all:compile link

compile:
	g++ -I src/include -c sources/*.cpp -c main.cpp 
link:
	g++ *.o -o cerveau
