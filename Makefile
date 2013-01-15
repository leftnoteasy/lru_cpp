FLAGS = -O3 -Wall -msse2 -m64 -flax-vector-conversions -lpthread -g

./example: lru_cache.o example.o

lru_cache.o: src/lru_cache.cpp src/lru_cache.h
	g++ $(FLAGS) -c src/lru_cache.cpp -o lru_cache.o
example.o: src/example.cpp
	g++ $(FLAGS) -c src/example.cpp example.o
clean:
	rm *.o example