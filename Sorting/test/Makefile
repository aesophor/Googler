CXX=g++
CXXFLAGS=-g -std=c++14 -I.. -flto -Os -Wall
TEST=sort_test
TEST_SRC:=$(TEST).cc
SRC=$(filter-out $(TEST_SRC), $(wildcard ../*.cc))

all:
	make $(TEST)

%: %.cc
	$(CXX) -o $(notdir $@) $< $(SRC) $(CXXFLAGS)

clean:
	rm *_test
