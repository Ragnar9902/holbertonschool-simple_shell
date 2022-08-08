#ifndef FILE_MAIN
#define FILE_MAIN

/* Libraries (#include) */
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/* Prototypes */
int hsh_cd(char **args);
int hsh_help(char **args);
int hsh_env(char **args);
int hsh_exit(char **args);
char *hsh_read_line(void);
char **hsh_split_line(char *line);
int hsh_launch(char **args);
int hsh_execute(char **args);
void hsh_loop(void);
int hsh_num_builtins(void);

/* Macros */
#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
extern char **environ;


#endif
