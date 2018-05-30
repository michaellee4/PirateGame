main: Pirate.o
		g++ Pirate.o -o main -lsfml-graphics -lsfml-window -lsfml-system

Pirate.o: Pirate.cpp
		g++ -c Pirate.cpp

clean:
	rm main
