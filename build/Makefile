
CFLAGS := `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -Wall -lSDL2_image -lm -Wall -Wextra
DIRS := ../src
SRCS := $(DIRS)/main.c
OBJS := $(SRCS:.c=.o)
EXEC :=  program
HDRS := # Add your header files here

all: $(EXEC)

clean:
	@rm -f $(EXEC) $(OBJS)
	@echo "clean executed Success"

$(EXEC): $(OBJS) $(HDRS) Makefile
	@$(CC) -o $@ $(OBJS) $(CFLAGS)

.PHONY: all clean