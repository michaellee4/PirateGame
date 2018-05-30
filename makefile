main: Pirate.o
		g++ -std=c++11 Pirate.o -o main -lsfml-graphics -lsfml-window -lsfml-system

Pirate.o: Pirate.cpp
		g++ -std=c++11 -c Pirate.cpp

clean:
	rm main Pirate.o
