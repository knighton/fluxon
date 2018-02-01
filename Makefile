all:
	@mkdir -p bin/
	clang++ -O3 -std=c++14 -Wpedantic -Wall -Wextra -Werror -Isrc/ src/main.cpp -o bin/spike

clean:
	rm -rf bin/
