SOURCES=$(wildcard *.cpp)
HEADERS=$(wildcard *.h)
OBJECTS=$(SOURCES:%.cpp=%.o)
FLAGS=-g -std=c++17
TARGET=Pizza

all: $(TARGET)
$(TARGET): $(OBJECTS) $(HEADERS)
	@echo "Now Generating $(TARGET) ..."
	g++ $(OBJECTS) $(LIB) $(FLAGS) -o $(TARGET)
%.o: %.cpp $(HEADERS)
	@echo "Now Compiling $< ..."
	g++ -I. -c $(FLAGS) $< -o $@
clean:
	rm *.o *.bak
explain:
	@echo "Headers: $(HEADERS)"
	@echo "Sources: $(SOURCES)"
	@echo "Objects: $(OBJECTS)"
	@echo "Target: $(TARGET)"
