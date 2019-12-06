CC=g++
CFLAGS=-std=c++14
EXEC=exe

run: build
	./$(EXEC)

build: main.cpp func.cpp
	$(CC) $(FLAGS) -o $(EXEC) $^

clean:
	rm -f $(EXEC)
