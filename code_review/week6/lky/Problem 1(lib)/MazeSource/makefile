lSOURCES=$(wildcard *.cxx)
sSOURCES=$(wildcard *.cpp)
HEADERS=$(wildcard *.h)
lOBJECTS=$(lSOURCES:%.cxx=%.o)
sOBJECTS=$(sSOURCES:%.cpp=%.o)
TARGET=maze.exe
LIB=maze.a

all: $(TARGET) $(LIB)
$(TARGET): $(HEADERS) $(LIB)
	@echo "Now Generating $(TARGET) ..."
	g++ $(LIB) -o $(TARGET)
$(LIB): $(lOBJECTS) $(sOBJECTS) $(HEADERS)
	@echo "Now Generating $(LIB) ..."
	ar -rv $(LIB) $(lOBJECTS) $(sOBJECTS)
	ranlib $(LIB)
%.o: %.cpp $(HEADERS)
	@echo "Now Compiling $< ..."
	g++ -c $< -o $@
%.o: %.cxx $(HEADERS)
	@echo "Now Compiling $< ..."
	g++ -c $< -o $@
clean:
	del *.o *.exe *.bak *.a
explain:
	@echo "Lib Sources: $(lSOURCES) $(sSOURCES)"
	@echo "Lib Objects: $(lOBJECTS) $(sOBJECTS)"
	@echo "Lib: $(LIB)"
	@echo "Target: $(TARGET)"
