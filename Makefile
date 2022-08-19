error = -Wall -pedantic -Werror -Wextra -std=gnu89

all: main

main:
	gcc $(error) -g *.c -o hsh
