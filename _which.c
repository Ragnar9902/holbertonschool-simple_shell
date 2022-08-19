#include "main.h"
/**
 * _which - searches directories in PATH variable for command
 * @filename: full path of command to execute
 * Return: pointer to full_path
 */

char *_which(char *filename)
{
	char *path, *tmp_path, *token;
	char *slash;
	int size;


	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	token = strtok(path, ":");

	size = strlen(filename) + 2;
	slash = malloc(size * sizeof(char));
	slash = strcpy(slash, "/");
	slash = strcat(slash, filename);

	while (token != NULL)
	{
		tmp_path = malloc(strlen(token) + size);
		tmp_path = strcpy(tmp_path, token);
		tmp_path = strcat(tmp_path, slash);

		if (is_executable(tmp_path) == PERMISSIONS)
		{
			free(slash);
			free(path);
			return (tmp_path);
		}
		token = strtok(NULL, ":");

		free(tmp_path);
	}

	free(path);
	free(slash);

	return (NULL);
}
/**
 * is_executable - Check if a filename have permissions
 * for run
 *
 * @filename: Filename to check
 *
 * Return: On success, PERMISSIONS
 * On error, NON_PERMISSIONS
 **/
int is_executable(char *filename)
{
	struct stat stats;

	if (stat(filename, &stats) == 0)
	{
		if (stats.st_mode & X_OK)
			return (PERMISSIONS);
		else
			return (NON_PERMISSIONS);
	}

	return (NON_FILE);
}
