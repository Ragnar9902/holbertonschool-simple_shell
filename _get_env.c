#include "main.h"
/**
 * _getenv - gets an environment variable
 * @name: environment variable to get
 * Return: pointer to environment variable or NULL if there is no match
 */
char *_getenv(const char *name)
{
	char **env;
	char *aux, *token, *value;
	size_t size;

	size = strlen((char *) name);

	for (env = environ; *env; ++env)
	{
		aux = strdup(*env);

		token = strtok(aux, "=");
		if (token == NULL)
		{
			free(aux);
			return (NULL);
		}

		if (strlen(token) != size)
		{
			free(aux);
			continue;
		}

		if (strcmp((char *) name, aux) == 0)
		{
			token = strtok(NULL, "=");
			value = strdup(token);

			free(aux);
			return (value);
		}

		free(aux);
	}

	return (NULL);
}

/**
 * copy_env - copies environment variable
 * @environ_copy: pointer to copy of environment variable
 * @environ_length: length of environment variable
 * Return: double pointer to copy of environment variable
 */
char **copy_env(char **environ_copy, unsigned int environ_length)
{
	char *variable;
	unsigned int variable_length;
	unsigned int i;

	environ_copy = malloc(sizeof(char **) * (environ_length));
	if (environ_copy == NULL)
	{
		perror("Error printed by perror");
		return (NULL);
	}

	i = 0;
	while (i < environ_length)
	{
		variable = environ[i];
		variable_length = strlen(variable);

		environ_copy[i] = malloc(sizeof(char) * variable_length + 1);
		if (environ_copy[i] == NULL)
		{
			perror("Error printed by perror");
			return (NULL);
		}
		strcpy(environ_copy[i], environ[i]);
		i++;
	}

	return (environ_copy);
}
