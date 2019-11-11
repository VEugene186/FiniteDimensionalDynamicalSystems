all: method
	g++ --std=c++11 -O3 Sample1/main.cpp -o bin/Sample1

equation: checkdir
	g++ --std=c++11 -O3 Equation/Parameter.cpp -c -o bin/Parameter.o
	g++ --std=c++11 -O3 Equation/PhaseVariable.cpp -c -o bin/PhaseVariable.o
	g++ --std=c++11 -O3 Equation/StateVector.cpp -c -o bin/StateVector.o
	g++ --std=c++11 -O3 Equation/Equation.cpp -c -o bin/Equation.o

method: equation
	g++ --std=c++11 -O3 Methods/Method.h -c -o bin/Method.o
	g++ --std=c++11 -O3 Methods/RungeKuttaMethod.h -c -o bin/RungeKuttaMethod.o
	g++ --std=c++11 -O3 Methods/ExplicitRungeKuttaMethod.h -c -o bin/ExplicitRungeKuttaMethod.o
	g++ --std=c++11 -O3 Methods/ClassicRungeKuttaMethod.h -c -o bin/ClassicRungeKuttaMethod.o
	
clean:
	rm -rf bin
	
checkdir:
	@if [ ! -d bin ]; then mkdir bin; fi