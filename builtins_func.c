#include "main.h"
/*
 * Builtin function implementations.
*/

/**
 * hsh_num_builtins - return the number of in built functions
 *
 * Return: number of built in functions
 */
int hsh_num_builtins(void)
{
	int builtins_num_func = 4;

	return (builtins_num_func);

}
/**
 * hsh_cd - change the current working directory
 * @args: arguments of the command
 * Return: always return 1
 */

int hsh_cd(char **args)
{

	if (args[1] == NULL)

		fprintf(stderr, "lsh: expected argument to \"cd\"\n");

	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("lsh");
		}
	}
	return (1);

}
/**
 * hsh_help - print general informations about hsh simple shell
 * @args: arguments of the command
 * Return: always return 1
 */

int hsh_help(char **args)
{
	int i;
	char *builtin_str[] = {
	"cd",
	"help",
	"exit",
	"env"
	};

	if (args[1] == NULL)
	{
		printf("simple shell\n");
		printf("Type program names and arguments, and hit enter.\n");
		printf("The following are built in:\n");
	}
	for (i = 0; i < hsh_num_builtins(); i++)
	{
		printf("  %s\n", builtin_str[i]);
	}

	printf("Use the man command for information on other programs.\n");
	return (1);

}
/**
 * hsh_exit - finish the current process
 * @args: arguments of the command
 * Return: always return 0
 */

int hsh_exit(char **args)
{
	if (args[0] == NULL)
		return (0);

	exit(EXIT_SUCCESS);
	return (2);

}
/**
 * hsh_env - print the enviromental varibles
 * @args: arguments of the command
 * Return: always return 1
 */

int hsh_env(char **args)
{
	char **tmp;
	int i;

	if (args[0] == NULL)
		return (0);

	for (i = 0, tmp = environ; tmp[i] != NULL; i++)
	{
		printf("%s", tmp[i]);
		putchar('\n');
	}
	return (1);

}
