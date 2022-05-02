CC = gcc
CFLAGS = -Wall -g -std=c99

BIN = ./bin/
SRC = ./src/

program: $(BIN)main.o $(BIN)word.o $(BIN)HashTableAPI.o
	$(CC) $(CFLAGS) $(BIN)word.o $(BIN)HashTableAPI.o $(BIN)main.o -Iinclude -o $(BIN)program

test: $(BIN)testmain.o $(BIN)word.o $(BIN)HashTableAPI.o
	$(CC) $(CFLAGS) $(BIN)word.o $(BIN)HashTableAPI.o $(BIN)testmain.o -Iinclude -o $(BIN)testing
$(BIN)HashTableAPI.o:$(SRC)HashTableAPI.c
	$(CC) $(CFLAGS) -Iinclude -c $(SRC)HashTableAPI.c -o $(BIN)HashTableAPI.o
$(BIN)word.o:$(SRC)word.c 
	$(CC) $(CFLAGS) -Iinclude -c $(SRC)word.c -o $(BIN)word.o
$(BIN)testmain.o: $(SRC)testmain.c
	$(CC) $(CFLAGS) -Iinclude -c $(SRC)testmain.c -o $(BIN)testmain.o
$(BIN)main.o: $(SRC)main.c
	$(CC) $(CFLAGS) -Iinclude -c $(SRC)main.c -o $(BIN)main.o
cls:
	clear
