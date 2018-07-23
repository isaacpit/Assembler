CXX = g++
CXXFLAGS = -std=c++14

targ = proj6

all: main

main: $(targ).o
	$(CXX) $(CXXFLAGS) -o main $(targ).o

$(targ).o: $(targ).cpp Instruction.h
	$(CXX) $(CXXFLAGS) -c $(targ).cpp 

compare: compare.o
	$(CXX) $(CXXFLAGS) -o compare compare.o

compare.o: compare.cpp
	$(CXX) $(CXXFLAGS) -c compare.cpp

clean: 
	rm *.o
	rm main
	rm compare 