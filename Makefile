# -- VARIABLES -- #
SHELL := /bin/sh
NAME := shorthand
CC := gcc
CFLAG = -I$(LIB) -Wall -Werror
RM := rm -f
INCLUDE =
LIB := lib
BUILD := build
OBJ = main.o

# Uncomment bellow to suffer
#CFLAG += -Wfatal-errors -Wextra -ansi -pedantic

all: build

# -- BUILD EXECULTABLE -- #
build: $(OBJ)
	$(CC) $(CFLAG) $(BUILD)/$^ -o $(BUILD)/$(NAME)
# -- COMPILE OBJECTS -- #
main.o: src/main.c
	mkdir -p $(BUILD)
	$(CC) $(CFLAG) -c $< -o $(BUILD)/$@

$(LIB)/%.o: $(LIB)/%.c
	$(CC) $(CFLAG) -c $< -o $(BUILD)/$@

# -- CLEAN REPO OF JUNK -- #
clean:
	$(RM) $(BUILD)/*.o

# -- TURN INTO FRESH REPO -- #
fresh: clean
	$(RM) $(BUILD)/$(NAME)

.PHONY: all clean fresh
