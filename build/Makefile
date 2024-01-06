CC = clang
CFLAGS := `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -Wall -lm -Wall -Wextra -pedantic
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
	@$(CC) -o $@ $(OBJS) $(CFLAGS)



run: clean all
	./$(EXEC)
		

.PHONY: all clean