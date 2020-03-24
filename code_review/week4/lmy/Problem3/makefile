TARGET=ObjNum

CC=g++
CFLAGS=-g -std=c++17
HEADER=$(TARGET).h

all: $(TARGET) clean

$(TARGET): main.o $(TARGET).o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.cpp $(HEADER)
	$(CC) -c $(CFLAGS) main.cpp -o $@

$(TARGET).o: $(TARGET).cpp $(HEADER)
	$(CC) -c $(CFLAGS) $(TARGET).cpp -o $@

clean: $(TARGET)
	rm $(TARGET).o main.o
