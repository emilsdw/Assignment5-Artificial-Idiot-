program: src/Artificial_idiot.cpp src/reader.cpp src/generator.cpp src/reader.h src/generator.h
	g++ -Wall -Wextra -std=c++17 src/Artificial_idiot.cpp src/reader.cpp src/generator.cpp -o slm

.PHONY: clean
clean:
	rm -f slm
	