program: main.cpp reader.cpp generator.cpp reader.h generator.h
	g++ -Wall -Wextra -std=c++17 main.cpp reader.cpp generator.cpp -o program

.PHONY: clean
clean:
	rm -f program