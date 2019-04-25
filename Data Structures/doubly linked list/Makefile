CXX=g++
CXXFLAGS=-g -std=c++11 -flto -Os -Wall
SRC=$(wildcard *.cc)
BIN=test

all:
	$(CXX) -o $(BIN) $(SRC) $(CXXFLAGS)

clean:
	rm $(BIN)

test:
	./$(BIN)
