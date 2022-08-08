#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "main.h"

/**
 * main - Main function for shell
 * Return: Always 1
 */
int main(void)
{
	hsh_loop();
	return (1);
}
