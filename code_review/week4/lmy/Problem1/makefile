TARGET=Member

CC=g++
CFLAGS=-O2 -std=c++17
HEADER=member.h

all: $(TARGET) clean

$(TARGET): main.o member.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.cpp $(HEADER)
	$(CC) -c $(CFLAGS) main.cpp -o $@

member.o: member.cpp $(HEADER)
	$(CC) -c $(CFLAGS) member.cpp -o $@

clean: $(TARGET)
	rm member.o main.o
