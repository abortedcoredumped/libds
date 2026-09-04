CC = gcc
INC = include
OUT = build
SRC = $(wildcard *.c) test/test.c

.PHONY: test
test:
	mkdir -p $(OUT)
	$(CC) -I $(INC) $(SRC) -o $(OUT)/main

clean:
	rm -rf $(OUT)/*

run:
	$(OUT)/main