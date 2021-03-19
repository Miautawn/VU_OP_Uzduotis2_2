build:
	g++ -o program main.cpp Extensions/*.cpp -O2

build_all:
	g++ -o program main.cpp *.o

compile_all:
	g++ -c Extensions/*.cpp -O2

clean:
	rm *.o bench* Benchmark/* 