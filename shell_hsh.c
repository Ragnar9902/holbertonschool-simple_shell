#include "main.h"

/*
 * List of builtin commands, followed by their corresponding functions.
 */
int (*builtin_func[]) (char **) = {
	&hsh_cd,
	&hsh_help,
	&hsh_exit,
	&hsh_env
};
/**
 * hsh_read_line - read the user command as a string
 *
 * Return: a string with the command
 */

char *hsh_read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0; /* have getline allocate a buffer for us */
	ssize_t c_r = 0;

	c_r = getline(&line, &bufsize, stdin);
	if (c_r == EOF)
	{
		exit(EXIT_SUCCESS);  /* We recieved an EOF*/
	}

	return (line);
}
/**
 * hsh_split_line - split a string in his words a return a vector to string
 * @line: string line
 * Return: **tokens words in line
 */

char **hsh_split_line(char *line)
{
	int bufsize = LSH_TOK_BUFSIZE, position = 0;
	char **tokens = NULL;
	char *token;

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		perror("lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, HSH_TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, HSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}
/**
 * hsh_launch - create two process and call the execve function
 * @args: arguments of the command
 * @envs: environment varibles
 * Return: 1 if the command execute right and
 * 0 if there is a error
 */

int hsh_launch(char **args, char **envs)
{
	pid_t pid;
	int status;
	char *fullpath = NULL;
	/*char *namefile = (char *)malloc(200 * sizeof(char));*/

	/*strcat(namefile, "/bin/");*/

	/*strcat(namefile, args[0]);*/

	/*path = _getenv("PATH");*/
	/*printf("%s", path);*/
	fullpath = _which(args[0]);
	/*printf("\n%s", fullpath);*/
	if (fullpath == NULL)
	{	fullpath = args[0];
	}
	pid = fork();
	if (pid == 0)
	{                     /* Child process*/

		if (execve(fullpath, args, envs) == -1)
			perror("lsh");
		/*free(namefile);*/
		exit(EXIT_FAILURE);
	} else if (pid < 0)                    /* Error forking*/
		perror("lsh");
	else                    /* Parent process*/
		waitpid(pid, &status, WUNTRACED);

	return (1);
}
/**
 * hsh_execute - execute the command
 * @args: arguments of the command
 * @envi: enviroment variables
 * Return: output of the functions called
 */

int hsh_execute(char **args, char **envi)
{
	int i = 0;
	char *builtin_str[] = {
	"cd",
	"help",
	"exit",
	"env"
	};


	if (args[0] == NULL)    /* An empty command was entered.*/
		return (1);

	for (i = 0; i < hsh_num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
			return ((*builtin_func[i])(args));
	}

	return (hsh_launch(args, envi));
}
/**
 * hsh_loop - main loop of the shell in which is printed the command pront
 * @av: argument pass to the main loop
 * Return: void
 */

void hsh_loop(char **av)
{
	char *line = NULL;
	char **args = NULL;
	int status = 1;

	args = av;
	while (status)
	{
		status = isatty(STDIN_FILENO);
		if (status)
		{
			printf("#cisfun$");
		}
		line = hsh_read_line();
		args = hsh_split_line(line);
		status = hsh_execute(args, environ);
		free(line);
		free(args);
		if (isatty(STDIN_FILENO) == 0)
		{
			break;
		}

	}
}
