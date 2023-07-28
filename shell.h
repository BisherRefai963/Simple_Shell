#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *args;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	listrifai_t *env;
	listrifai_t *history;
	listrifai_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} inforifai_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* toem_shloop.c */
int hsh(inforifai_t *, char **);
int find_builtin(inforifai_t *);
void find_cmd(inforifai_t *);
void fork_cmd(inforifai_t *);

/* toem_parser.c */
int is_cmd(inforifai_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* toem_errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* toem_str_func2.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* toem_str_func1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* toem_exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* toem_str_func3.c */
char **n_words(char *, char *);
char **strtow(char *, char);

/* toem_realloc.c */
char *_memset(char *, char, unsigned int);
void free_all(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* toem_memory.c */
int p_free(void **p);

/* toem bichr_atoi.c */
int interaction(inforifai_t *);
int is_delimeter(char, char *);
int _isleader(int);
int _automatic(char *);

/* toem_errors1.c */
int _erratoi(char *);
void print_error(inforifai_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* toem_builtin.c */
int _rifaiexit(inforifai_t *);
int _rifaicd(inforifai_t *);
int _rifaihelp(inforifai_t *);

/* toem_builtin1.c */
int _rifaihistory(inforifai_t *);
int _rifaimyalias(inforifai_t *);

/*toem_getline.c */
ssize_t get_input(inforifai_t *);
int rifai_getline(inforifai_t *, char **, size_t *);
void rifai_sigintHandler(int);

/* toem_getinfo.c */
void rifai_clear_info(inforifai_t *);
void rifai_set_info(inforifai_t *, char **);
void rifai_free_info(inforifai_t *, int);

/* toem_environ.c */
char *rifai_getenv(inforifai_t *, const char *);
int rifai_myenv(inforifai_t *);
int rifai_mysetenv(inforifai_t *);
int rifai_myunsetenv(inforifai_t *);
int rifai_populate_env_list(inforifai_t *);

/* toem_getenv.c */
char **rifai_get_environ(inforifai_t *);
int rifai_unsetenv(inforifai_t *, char *);
int rifai_setenv(inforifai_t *, char *, char *);

/* toem_history.c */
char *rifai_get_history_file(inforifai_t *inforifai);
int rifai_write_history(inforifai_t *inforifai);
int rifai_read_history(inforifai_t *inforifai);
int rifai_build_history_list(inforifai_t *inforifai, char *buf, int linecount);
int rifai_renumber_history(inforifai_t *inforifai);

/* toem_lists.c */
listrifai_t *rifai_add_node(listrifai_t **, const char *, int);
listrifai_t *rifai_add_node_end(listrifai_t **, const char *, int);
size_t rifai_print_list_str(const listrifai_t *);
int rifai_delete_node_at_index(listrifai_t **, unsigned int);
void rifai_free_list(listrifai_t **);

/* toem_lists1.c */
size_t rifai_list_len(const listrifai_t *);
char **rifai_list_to_strings(listrifai_t *);
size_t rifai_print_list(const listrifai_t *);
listrifai_t *rifai_node_starts_with(listrifai_t *, char *, char);
ssize_t rifai_get_node_index(listrifai_t *, listrifai_t *);

/* toem_vars.c */
int rifai_is_chain(inforifai_t *, char *, size_t *);
void rifai_check_chain(inforifai_t *, char *, size_t *, size_t, size_t);
int rifai_replace_alias(inforifai_t *);
int rifai_replace_vars(inforifai_t *);
int rifai_replace_string(char **, char *);

#endif

