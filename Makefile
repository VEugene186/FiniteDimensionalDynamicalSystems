all: checkdir
	g++ --std=c++11 -O3 Equation/Parameter.cpp -c -o bin/Parameter.o
	g++ --std=c++11 -O3 Equation/PhaseVariable.cpp -c -o bin/PhaseVariable.o
	g++ --std=c++11 -O3 Equation/Equation.cpp -c -o bin/Equation.o
	
	
clean:
	rm -rf bin
	
checkdir:
	@if [ ! -d bin ]; then mkdir bin; fi