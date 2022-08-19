#ifndef FILE_MAIN
#define FILE_MAIN

/* Libraries (#include) */
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/stat.h>
/*define macros*/
#define PROMPT "$ "

/* Global variable */
extern char **environ;
/* Prototypes */
int hsh_cd(char **args);
int hsh_help(char **args);
int hsh_env(char **args);
int hsh_exit(char **args);
char *hsh_read_line(void);
char **hsh_split_line(char *line);
int hsh_launch(char **args, char **envs, int status);
int hsh_execute(char **args, char **envi);
void hsh_loop(char **av);
int hsh_num_builtins(void);
char *_getenv(const char *name);
char **copy_env(char **environ_copy, unsigned int environ_length);
char *_which(char *command);
int is_executable(char *filename);

/* Macros */
#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_BUFSIZE 64
#define HSH_TOK_DELIM " \n\t\r\a\v"
#define _TRUE            1
#define _FALSE           0

#define STDIN            0
#define STDOUT           1
#define STDERR           2

#define NON_INTERACTIVE  0
#define INTERACTIVE      1

#define PERMISSIONS      1
#define NON_PERMISSIONS -1

#define _FILE            10
#define NON_FILE         -10

#define _ENOENT          "No such file or directory"
#define _EACCES          "Permission denied"
#define _CMD_NOT_EXISTS  "not found"
#define _ILLEGAL_NUMBER  "Illegal number"

#define _CODE_ENOENT           3
#define _CODE_EACCES           13
#define _CODE_CMD_NOT_EXISTS   132
#define _CODE_ILLEGAL_NUMBER   133
extern char **environ;


#endif
