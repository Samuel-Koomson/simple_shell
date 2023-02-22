#include "shell.h"

/**
 * cmp_env_name - Function that compares env var names with the name passed.
 * @nenv: Environment variable
 * @name: name passed
 * Return: 0 if  unequal, another value if equal.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenv - Function that get an environment variable
 * @name: Name of environment variable
 * @_environ: Environment variable
 * Return: value of environment variable if found or NULL if otherwise.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	mov = 0;
	/*
     * Compare all environment variables
     *  environ is declared in the header file
     */
	for (i = 0; _environ[i]; i++)
	{
		/* If name and env are equal*/
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env - Function that prints the evironment variables
 * @datash: Relevant data.
 * Return: 1 on success.
 */
int _env(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_environ[i]; i++)
	{

		for (j = 0; datash->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
