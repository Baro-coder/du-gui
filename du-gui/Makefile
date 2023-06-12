# Variables

## Compiler
CC = gcc

## Flags
CFLAGS = -Wall -Iinclude/ `pkg-config --cflags --libs gtk+-3.0` -export-dynamic

## Directories
### Binaries
DIR_BIN = bin/
### Includes
DIR_INC = include/
### Objects
DIR_OBJ = obj/
###  Sources
DIR_SRC = src/

## Target name
TARGET = $(DIR_BIN)du-gui


# Main build rule
all: $(TARGET)

$(TARGET): $(DIR_OBJ)app.o $(DIR_OBJ)controls.o $(DIR_OBJ)execute.o
	@echo " [*] Compiling $@ ..."
	@$(CC) $^ -o $@ -I$(DIR_INC) $(CFLAGS) 
	@echo "    Done."
	@echo
	@echo " Compilation is successfully finished!"


# Source to Object build rules
## Main file
$(DIR_OBJ)app.o: app.c
	@echo " Compilation is starting..."
	@echo
	@echo " [*] Compiling $< into $@ ..."
	@$(CC) -c $< -o $@ -I$(DIR_INC) $(CFLAGS)
	@echo "    Done."

## Controls handlers
$(DIR_OBJ)controls.o: $(DIR_SRC)controls.c
	@echo " [*] Compiling $< into $@ ..."
	@$(CC) -c $< -o $@ -I$(DIR_INC) $(CFLAGS)
	@echo "    Done."

## Execute `du` command handlers
$(DIR_OBJ)execute.o: $(DIR_SRC)execute.c
	@echo " [*] Compiling $< into $@ ..."
	@$(CC) -c $< -o $@ -I$(DIR_INC) $(CFLAGS)
	@echo "    Done."


# Clean rule
clean:
	@echo " [*] Cleaning..."
	@rm -f $(TARGET) obj/*.o
	@echo "  Done."