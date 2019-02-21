CXX=g++
CXXFLAGS=-g -std=c++14 -flto -Os -Wall
BIN=test
SRC=$(wildcard *.cpp)

all:
	$(CXX) -o $(BIN) $(SRC) $(CXXFLAGS)

run:
	./$(BIN)

clean:
	rm $(BIN)
