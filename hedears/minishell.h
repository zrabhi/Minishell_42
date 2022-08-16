//------------- global-header-file -----------------------------------------

#ifndef MINISHELL_H
# define MINISHELL_H

//------------- libraries -------------------------------------------------

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../LIBFT/libft.h"
# include <stdbool.h>
# include <stdlib.h>

//------------- typedefs --------------------------------------------------



# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define ERROR 1
# define SUCCESS 0

//-----------------abstract syntax tree-------------------------------------




//---------------------------structs----------------------------------------

typedef struct s_list
{
   char    *content;
    struct s_list *next;
    struct s_list *previous;
} t_list;

typedef enum s_tokens{
    WORD,
    SPC,
    EMPTY,
    S_QUOTES,
    D_QUOTES,
    APPEND,
    R_DERECTION,
    L_DERECTION,
    D_R_DERECTION,
    D_L_DERECTION,
    PIPE,
    DOLLAR,
} t_tokens;

typedef struct s_cmd
{
    char *str;
    t_tokens type;
    struct s_cmd *next;
}   t_cmd;

typedef struct s_data
{
    t_list  *list_head;
    t_list  *list_tail;
    t_cmd   *cmd;
} t_data;

//-------------- enum strcut contains ---------------------------------------


//---------------- functions --------------------------------------------

t_list *creat_node(char *content);
int     ft_pipe_check(char *line, t_tokens type);
int     check_user_input(char d, t_tokens type);
int     check_user_input(char d, t_tokens type);
void    ft_creat_lst(t_data **data, t_list *lst);
bool    ft_check_input(char *input);
void    ft_shell(char **av);
t_cmd   *pipe_parse(char *s, t_cmd *cmd);
char    *double_quotes_check(char *line);
bool    number_of_quotes(char *line);
char    *line_check(char *path);
t_cmd   *cmd_list(char *str, t_tokens token);
t_cmd   *get_str(char *str, t_tokens token, t_cmd *cmd);


//---------------- print fucntions------------------------------------------
void    print_lst(t_cmd *cmd);
void    print_tokens(t_cmd *cmd);

#endif
