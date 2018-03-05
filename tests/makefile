BINARY_DIR:=build
BINARY_FILENAME=test
BINARY_PATH=$(BINARY_DIR)/$(BINARY_FILENAME)

INCLUDE_MATH:=-I ../includes
INCLUDE_TEST:=-I ./includes
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

