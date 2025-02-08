CC = gcc
CFLAGS = -Wall -pedantic
LDFLAGS = -g3

all: main mainC

main: main.o matrice.o vecteur.o
	$(CC) $(LDFLAGS) $^ -o $@

mainC: main.o matriceC.o vecteur.o
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o main mainC
