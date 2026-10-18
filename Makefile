slm: src/Artificial_idiot.o src/reader.o src/generator.o
	g++ src/Artificial_idiot.o src/reader.o src/generator.o -o slm

src/Artificial_idiot.o: src/Artificial_idiot.cpp src/reader.h src/generator.h
	g++ -Wall -Wextra -std=c++17 -c src/Artificial_idiot.cpp -o src/Artificial_idiot.o

src/reader.o: src/reader.cpp src/reader.h
	g++ -Wall -Wextra -std=c++17 -c src/reader.cpp -o src/reader.o

src/generator.o: src/generator.cpp src/generator.h src/reader.h
	g++ -Wall -Wextra -std=c++17 -c src/generator.cpp -o src/generator.o

.PHONY: clean
clean:
	rm -f slm src/*.o