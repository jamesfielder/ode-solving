CXX=g++
CXXFLAGS+=-O2 -std=c++11

all: main

clean:
	rm -f main *.o

MVector.o:
	$(CXX) $^ $(CXXFLAGS) MVector.cpp -c

solvers.o:
	$(CXX) $^ $(CXXFLAGS) solvers.cpp -c

odes.o:
	$(CXX) $^ $(CXXFLAGS) odes.cpp -c

main.o:
	$(CXX) $^ $(CXXFLAGS) main.cpp -c

main: MVector.o solvers.o odes.o main.o
	$(CXX) $^ $(CXXFLAGS) -o $@

pygments:
	pygmentize -O linenos=ON -f latex main.cpp > ../main.cpp.tex
	pygmentize -O linenos=ON -f latex solvers.hpp > ../solvers.hpp.tex
	pygmentize -O linenos=ON -f latex MVector.hpp > ../mvector.tex
	pygmentize -O linenos=ON -f latex MFunction.hpp > ../MFunction.tex
	pygmentize -O linenos=ON -f latex MVector.cpp > ../MVector.cpp.tex
	pygmentize -O linenos=ON -f latex Makefile > ../makefile.tex
	pygmentize -O linenos=ON -f latex solvers.cpp > ../solvers.cpp.tex
	pygmentize -O linenos=ON -f latex odes.cpp > ../odes.cpp.tex
	pygmentize -O linenos=ON -f latex odes.hpp > ../odes.hpp.tex
