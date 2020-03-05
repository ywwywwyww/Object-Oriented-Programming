# Modified from the demo used in class.

SOURCES=$(wildcard *.cpp)
HEADERS=$(wildcard *.h)
OBJECTS=$(SOURCES:%.cpp=%.o)
COMPILER=g++
OPTIONS=-std=c++17 -Ofast
TARGET=assigner

all: $(TARGET)
$(TARGET): $(OBJECTS) $(HEADERS) $(LIB)
	@echo "Now Generating $(TARGET) ..."
	$(COMPILER) $(OBJECTS) $(LIB) -o $(TARGET) $(OPTIONS)
%.o: %.cpp $(HEADERS)
	@echo "Now Compiling $< ..."
	$(COMPILER) -c $< -o $@ $(OPTIONS)
%.o: %.cxx $(HEADERS)
	@echo "Now Compiling $< ..."
	$(COMPILER) -c $< -o $@ $(OPTIONS)
clean:
	rm -f $(TARGET) $(OBJECTS)
explain:
	@echo "Sources: $(SOURCES)"
	@echo "Objects: $(OBJECTS)"
	@echo "Target: $(TARGET)"
