TARGET=Matrix

CC=g++
CFLAGS=-g -std=c++17
HEADER=Matrix.h

all: $(TARGET) clean

$(TARGET): main.o Matrix.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.cpp $(HEADER)
	$(CC) -c $(CFLAGS) main.cpp -o $@

Matrix.o: Matrix.cpp $(HEADER)
	$(CC) -c $(CFLAGS) Matrix.cpp -o $@

clean: $(TARGET)
	rm Matrix.o main.o
