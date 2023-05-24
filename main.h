#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <wait.h>

/**
 * struct list - this is a linked list
 * @var: this the variable of the string
 * @next: this is the pointer to the next node
 */
typedef struct list
{
	char *var;
	struct list *next;

} list_t;

/* All Prototypes */
char **_str_tok(char *str, char *delm);
char **c_str_tok(char *str, char *delm);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *c_strdup(char *str, int cs);
char *_strdup(char *str);
char *_which(char *str, list_t *env);
char *get_env(char *str, list_t *env);
char *ignore_space(char *str);
char *int_to_string(int num);
int __exit(char **s, list_t *env, int num, char **command);
int _cd(char **str, list_t *env, int num);
int _env(char **str, list_t *env);
int _execve(char *argv[], list_t *env, int num);
int _setenv(list_t **env, char **str);
int _strcmp(char *s1, char *s2);
int _unsetenv(list_t **env, char **str);
int built_in(char **token, list_t *env, int num, char **command);
int delete_nodeint_at_index(list_t **head, int index);
int find_env(list_t *env, char *str);
int prompt(char **env);
int t_strlen(char *str, int pos, char delm);
list_t *add_end_node(list_t **head, char *str);
list_t *env_linked_list(char **env);
size_t get_line(char **str);
size_t print_list(list_t *h);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void cant_cd_to(char *str, int c_n, list_t *env);
void free_double_ptr(char **str);
void free_linked_list(list_t *list);
void illegal_number(char *str, int c_n, list_t *env);
void non_interactive(list_t *env);
void not_found(char *str, int num, list_t *env);

#endif
