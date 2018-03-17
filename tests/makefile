BINARY_DIR:=build
BINARY_FILENAME=test
BINARY_PATH=$(BINARY_DIR)/$(BINARY_FILENAME)

INCLUDE_MATH:=-I ../include
INCLUDE_TEST:=-I ./include
INCLUDE:=$(INCLUDE_MATH) $(INCLUDE_TEST)

CFLAGS:=-std=c++1z -O3 $(INCLUDE)

SRC:=src/main.cpp

all: build

.PHONY: build
build:
	mkdir -p $(BINARY_DIR)
	g++ $(CFLAGS) $(SRC) -o $(BINARY_PATH)

run: build
	./$(BINARY_PATH)

