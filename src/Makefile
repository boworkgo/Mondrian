EXE := helloMake
SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)
DEP := $(OBJ:.o=.d)
CPPFLAGS := -I../include
CPPFLAGS += -MMD -MP
CXXFLAGS := -Wall -W -pedantic
LDFLAGS := -L../lib
LDLIBS := -lm

.PHONY: all clean
all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean:
	$(RM) $(EXE) $(OBJ) $(DEP)

-include $(DEP)