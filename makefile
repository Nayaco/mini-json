
CXX = g++
CXXFLAG = --std=c++17 -O2

TO = to.o

$(TO): src/toEx/to.cpp
	$(CXX) -c src/toEx/to.cpp -o $(TO) $(CXXFLAG)

clean:
	rm $(TO)

