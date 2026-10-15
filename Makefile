program: Artificial_idiot.cpp reader.cpp generator.cpp reader.h generator.h
	g++ -Wall -Wextra -std=c++17 Artificial_idiot.cpp reader.cpp generator.cpp -o program

.PHONY: clean
clean:
	rm -f program