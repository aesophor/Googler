CXX=g++
CXXFLAGS=-g -std=c++14 -I.. -flto -Os -Wall
SRC=$(wildcard ../*.cpp)
TEST=doubly_linked_list_test \
     vector_test \
     stack_test \
     queue_test \
     circular_buffer_test \
     binary_search_tree_test

all:
	make $(TEST)

%: %.cpp
	$(CXX) -o $(notdir $@) $< $(SRC) $(CXXFLAGS)

clean:
	rm *_test
