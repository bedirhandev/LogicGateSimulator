GCC = g++ -std=c++17
SRCS = $(wildcard *.cpp)
OBJS = $(addprefix ./obj/, $(SRCS:.cpp=.o))
DEPS = $(SRCS:.cpp=.d)
LDFLAGS ?= -I ./inc
CPPFLAGS ?= -Wall -Werror
DBGFLAGS ?= -O0 -g
ENTRYPOINT ?= $(addprefix ./obj/, main.o)

main: $(ENTRYPOINT) $(OBJS)
	$(GCC) $(CPPFLAGS) $(DBGFLAGS) -o $@ $^ $(LDFLAGS)
	@echo EXECUTING FILE: ./main
	./main \

./obj/%.o: %.cpp
	$(GCC) -c -o $@ $< $(LDFLAGS)

.PHONY: clean

# $(RM) is rm -f by default
clean:
	$(RM) $(OBJS) $(DEPS) main 

-include $(DEPS)
