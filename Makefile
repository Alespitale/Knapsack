CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=c99 -g

all: main.o knapsack.o helpers.o item.o string.o sorter.o 
		$(CC) $(CFLAGS) -o knapsack main.o knapsack.o helpers.o item.o string.o sorter.o

main.o: main.c helpers.h knapsack.h
		$(CC) $(CFLAGS) -c main.c

helpers.o: helpers.h
		$(CC) $(CFLAGS) -c helpers.c

item.o: item.h helpers.h string.h
		$(CC) $(CFLAGS) -c item.c

string.o: string.h
		$(CC) $(CFLAGS) -c string.c

sorter.o: sorter.h item.h
		$(CC) $(CFLAGS) -c sorter.c

knapsack.o: knapsack.h
		$(CC) $(CFLAGS) -c knapsack.c

.PHONY: clean
clean:
		rm -f all main.o helpers.o item.o string.o knapsack.o sorter.o