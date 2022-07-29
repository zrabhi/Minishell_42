//------------- global-header-file -----------------------------------------

#ifndef MINISHELL_H
# define MINISHELL_H

//------------- libraries -------------------------------------------------

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>
//------------- typedefs --------------------------------------------------

typedef struct s_list
{
   char    *content;
    struct s_list *next;
    struct s_list *previous;
} t_list;

typedef enum s_tokens{
    QUOTES,
    D_QUOTES,
    R_DERECTION,
    L_DERECTION,
    D_R_DERECTION,
    D_L_DERECTION,
    PIPE,
    DOLLAR,
    WORD,
} t_tokens;

typedef struct s_cmd
{
    char **cmdline;
    int char_pointer;    
    t_tokens type;
    char quote;
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
int ft_pipe_check(char *line, t_tokens type);
int     check_user_input(char d, t_tokens type);
int check_user_input(char d, t_tokens type);
void    ft_creat_lst(t_data **data, t_list *lst);
bool    ft_check_input(char *input);
void    ft_shell(char **av);
t_cmd *pipe_parse(char *s, t_cmd *cmd);
char *double_quotes_check(char *line);
bool number_of_quotes(char *line);


#endif
