#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "main.h"

/**
 * signal_handler - handle the process interrept signal
 * @signo: the signal identifier
 *
 * Return: void
 */
void signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		printf("\n");
		printf(PROMPT);
	}
}
/**
 * main - Main function for shell
 * @argc: number of arg pass to execute
 * @argv: list arguments pass to execute
 * Return: Always 1
 */
int main(int argc __attribute__((unused)), char **argv, char **environ)
{
	signal(SIGINT, signal_handler);
	hsh_loop(argv, environ);
	return (1);
}
