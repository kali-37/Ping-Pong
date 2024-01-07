CC = clang
CFLAGS = `sdl2-config --cflags` -ggdb3 -O3 --std=c99 -Wall -Wall -Wextra -pedantic
LDFLAGS := `sdl2-config --libs` -lm
DIRS_src = ../src
DIRS_headers = ../headers
SRCS = $(wildcard $(DIRS_src)/*.c)
OBJS = $(SRCS:.c=.o)
EXEC =  program.out
HDRS = $(wildcard $(DIRS_headers)/*.h) 

all: $(EXEC)

clean:
	@rm -f $(EXEC) $(OBJS)
	@echo "clean executed Success"

$(EXEC): $(OBJS) $(HDRS)
	@$(CC) -o $@ $(OBJS) $(CFLAGS) $(LDFLAGS)



run: clean all
	./$(EXEC)
		

.PHONY: all clean