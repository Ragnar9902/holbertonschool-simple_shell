#include "general.h"
#include "text.h"
#include "commands.h"
/**
 * replacement - analyze the imput format
 * @info: data struct that contain all the information
 * @index: line read and parsed
 * @string: cahin to be rleplaced
 * Return: void
 */

char *replacement(general_t *info, int *index, char *string)
{
	char *tmp;
	char symbol;

	(void) index;

	symbol = *string;
	if (symbol != '?' && symbol != '$')
	{
		tmp = replace_env(info, string);
		return (tmp);
	}

	tmp = (symbol == '$') ? to_string(info->pid) :
		to_string(info->status_code);

	return (tmp);
}
/**
 * replace_env - analyze the imput format
 * @info: data struct that contain all the information
 * @environment: line read and parsed
 * Return: void
 */


char *replace_env(general_t *info, char *environment)
{
	char *env;

	(void) info;

	env = _getenv(environment);
	if (env != NULL)
		return (env);

	return (NULL);
}

