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
#define INFO_INIT { 0 }

/* for conver_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".somple_shell_history"
#define HIST_MAX	4096

extern char **environ;

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: Points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;
/**
 * struct passinfo - contains pseudo_arguements to pass into a function
 * @arg: a string generted from getline containing arguements
 * @argv: an srray of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: the error code for exit()s
 * @linecount_flag:if on count this line of input
 * @fname: the program filename
 * @env: linked list local copy of environ
 * @environ: custon modified copy of environ from LL env
 * @history: the history node
 * @alias: the alias node
 * @env_swap: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of pointerto cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readpd: the fd from which to read line input
 * @histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_swap;
	int status;

	char **cmd_buf;
	int cmd_buf_type;

