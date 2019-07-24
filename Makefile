CXXFLAGS = -Wall -g -Iinclude
CXX=g++

src = $(wildcard src/*.cpp)
obj = $(src:.cpp=.o)

Sorting: $(obj)
	$(CXX) -g -o $@ $^

.PHONY: clean

clean:
	rm -f src/*.o
