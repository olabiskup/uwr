FLAGS = `pkg-config --libs --cflags gtk+-3.0` -Wall -Wextra -std=c11

default: saper

saper: main.o play.o minesweeper.o
	gcc main.o play.o minesweeper.o ${FLAGS} -o saper

%.o: %.c
	gcc -c ${FLAGS} $< -o $@

clean:
	-rm -f *.o saper