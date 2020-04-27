sSOURCES=$(wildcard *.cpp) $(wildcard *.cxx) $(wildcard pizza/*.cpp) $(wildcard generator/*.cpp) $(wildcard pizza_factory/*.cpp) $(wildcard pizza_heap/*.cpp) $(wildcard pizza_store/*.cpp) $(wildcard timer/*.cpp) $(wildcard sorter/*.cpp)
HEADERS=$(wildcard *.h) $(wildcard pizza/*.h) $(wildcard generator/*.h) $(wildcard pizza_factory/*.h) $(wildcard pizza_heap/*.h) $(wildcard pizza_store/*.h) $(wildcard timer/*.h) $(wildcard sorter/*.h)
sOBJECTS=$(sSOURCES:%.cpp=%.o)
TARGET=$(shell pwd |sed 's/^\(.*\)[/]//' )
LIB=$(wildcard *.a)

all: $(TARGET)
$(TARGET): $(sOBJECTS) $(HEADERS) $(LIB)
	@echo "Now Generating $(TARGET) ..."
	g++ $(sOBJECTS) $(LIB) -o $(TARGET)
%.o: %.cpp $(HEADERS)
	@echo "Now Compiling $< ..."
	g++ -c $< -o $@ -std=c++17
%.o: %.cxx $(HEADERS)
	@echo "Now Compiling $< ..."
	g++ -c $< -o $@ -std=c++17
clean:
	rm -f $(TARGET) $(sOBJECTS)
explain:
	@echo "User Sources: $(sSOURCES)"
	@echo "User Objects: $(sOBJECTS)"
	@echo "Target: $(TARGET)"
