#include "../hedears/minishell.h"

int check_user_input(char d, t_tokens type)
{
   if (d == '|')
       return (type = PIPE);
    // if (d == '')
    //     return(type == SPC);
    else if (d == '\"')
        return(type = D_QUOTES);
    else if (d == '\'')
        return(type = S_QUOTES);
    else if (d == '<')
        return (type = L_DERECTION);
    else if (d == '>')
        return(type = R_DERECTION);
    else if (d == '$')
        return (type = DOLLAR);
    return(0);
}


void arg_type(t_cmd *cmd)
{
    if (ft_strcmp(cmd->str, "") == 0)
        cmd->type = EMPTY;
    else if (ft_strcmp(cmd->str, " ") == 0)
        cmd->type = SPC;
    else if (ft_strcmp(cmd->str, "|") == 0)
        cmd->type = PIPE;
    else if(ft_strcmp(cmd->str, "\"") == 0)
        cmd->type = D_QUOTES;
    else if(ft_strcmp(cmd->str, "\'") == 0)
        cmd->type =S_QUOTES;
    else if(ft_strcmp(cmd->str, ">>") == 0)
        cmd->type = APPEND;    
}

void    ft_space_skip(char *line, int *i)
{
    if (*line == ' ' || *line == '\t' || *line == '\v' 
        || *line == '\r')
        (*i)++;
}
void increment(int *i)
{
    (*i)++;
}
  
t_cmd    *get_str(char *str, t_tokens token, t_cmd *cmd)
{
    int     i;
     int     j;
    void    *line;
    char    *operator;

    // cmd = NULL;
    i = 0;
    j = 0;
    while (str[i])
    {
        ft_space_skip(str, &i);
        if (check_user_input(str[i + 1], token))
        {
            i++;
            operator = ft_substr(str, i, 1); 
            token = check_user_input(str[i], token);
            line = ft_substr(str, j, i);
            cmd = cmd_list((char *)line, token);
            printf("line = %s\n", cmd->str);
            printf(" line type = %d\n", cmd->type);
            cmd = cmd_list(operator, token);
            printf("operator = %s\n", cmd->str);
            printf(" operator type = %d\n", cmd->type);
            j = i;
        free(line);
        }
        // else if(!check_user_input(str[i + i]))
        i++;
    }
    free(operator);
    free(line);
    return (cmd);
}

void    token_args(t_cmd *cmd)
{
    t_cmd *tmp;

    tmp = cmd;
    while(tmp)
    {
        arg_type(tmp);
        tmp = tmp->next;
    }
    print_tokens(cmd);
}

char    *line_check(char *path)
{   
    int i;
    char *str = NULL;

    i = 0;

    // str = ft_strdup("");
    if (!path)   
        return( NULL);
    while (path[i] && path[i] != ' ')
            i++;
    if (path[i] == ' ')
    {
        i = 0;
        str = malloc(sizeof(char) * (i + 1));
        if (!str)
            return (NULL);
        while (path[i] != ' ')
        {
            str[i] = path[i];
            i++;
        }
        str[i] = '\0';
    }   
    // if (path[i] == ' ' )
    //     str = ft_strdup(path);
    return (str);
}







// t_cmd *tokanization(char *line)
// {
//     int i;
//     char *str;
//     i = 0;

//     str = line;
//     while (str[i])
//     {
//         if (check_user_input)

//     }
// }

// int  ft_skip_space(char d)
// {
//     if (d == ' ')
//         return(1);
//     return(0);
// }