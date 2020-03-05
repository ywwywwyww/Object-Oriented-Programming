run.exe: polynomial.o posynomial.o timer.o main.o func.h timer.h
	g++ polynomial.o posynomial.o timer.o main.o -o run.exe
polynomial.o: polynomial.cpp func.h
	g++ -c polynomial.cpp -o polynomial.o
posynomial.o: posynomial.cpp func.h
	g++ -c posynomial.cpp -o posynomial.o
timer.o: timer.cpp timer.h
	g++ -c timer.cpp -o timer.o
main.o: main.cpp func.h timer.h
	g++ -c main.cpp -o main.o
clean:
	rm *.o *.exe
