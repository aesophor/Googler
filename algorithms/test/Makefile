CXX=g++
CXXFLAGS=-g -std=c++14 -I.. -flto -Os -Wall
TEST=sort_test
TEST_SRC:=$(TEST).cpp
SRC=$(filter-out $(TEST_SRC), $(wildcard ../*.cpp))

all:
	make $(TEST)

%: %.cpp
	$(CXX) -o $(notdir $@) $< $(SRC) $(CXXFLAGS)

clean:
	rm *_test
