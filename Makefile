error = -Wall -pedantic -Werror -Wextra -std=gnu89

all: main

main: main.c
	gcc $(error) -g *.c -o hsh
