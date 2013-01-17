FLAGS = -c -O3 -Wall -g

CC=g++

all: lru_cache

lru_cache: example.o lru_cache.o
	$(CC) example.o lru_cache.o

example.o: lru_cache.o example.cpp
	$(CC) $(FLAGS) example.cpp

lru_cache.o: lru_cache.cpp
	$(CC) $(FLAGS) lru_cache.cpp

clean:
	rm -rf *.o lru_cache