CXX=g++
CXXFLAGS=-g -std=c++14 -I.. -flto -Os -Wall
SRC=$(wildcard *.cpp)
TEST=doubly_linked_list_test \
     vector_test \
     stack_test \
     queue_test

all:
	make $(TEST)

test: %.cpp
	$(CXX) -o $(notdir $@)test $< $(CXXFLAGS)

run:
	./$(BIN)

clean:
	rm $(BIN)
