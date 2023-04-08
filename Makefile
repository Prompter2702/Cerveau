all:compile link

compile:
	g++ -I src/include -c Source/*.cpp -c main.cpp 
link:
	g++ *.o -o cerveau
