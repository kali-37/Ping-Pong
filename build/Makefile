CC = clang
CFLAGS = $(shell sdl2-cofig --cflags) -ggdb3 -O0 --std=c99 -Wall -Wall -Wextra -pedantic
LDFLAGS := $(shell sdl2-config --libs) -lm
DIRS = ../src
SRCS = $(wildcard $(DIRS)/*.c)
OBJS = $(SRCS:.c=.o)
EXEC =  program.out
HDRS = # Add your header files here

all: $(EXEC)

clean:
	@rm -f $(EXEC) $(OBJS)
	@echo "clean executed Success"

$(EXEC): $(OBJS) $(HDRS)
	@$(CC) -o $@ $(OBJS) $(CFLAGS) $(LDFLAGS)



run: clean all
	./$(EXEC)
		

.PHONY: all clean