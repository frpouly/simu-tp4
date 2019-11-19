CXX = g++
CC = gcc

CXXSRC=main.cpp Rabbit.cpp
#SRC=$(wildcard *.cpp)
CSRC=rand.c
EXE=simu_tp4

CXXFLAGS = -Wall -Wextra -MMD -g
CFLAGS = -Wall -Wextra -lm -g
LDFLAGS =

OBJ=$(addprefix build/,$(CXXSRC:.cpp=.o))
DEP=$(addprefix build/,$(SRC:.cpp=.d))
OBJ+=$(addprefix build/,$(CSRC:.c=.o))


all: $(OBJ)
	$(CXX) -o $(EXE) $^ $(LDFLAGS)


build/%.o: %.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ -c $<
	
build/%.o: %.c
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf build core *.gch

-include $(DEP)
