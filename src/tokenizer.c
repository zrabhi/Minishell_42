#include "../hedears/minishell.h"

int check_user_input(char d, t_tokens type)
{
   if (d == 124)
       return (type = PIPE);
    if (d == 32)
        return(type == SPC);
    else if (d == 34)
        return(type = D_QUOTES);
    else if (d == 39)
        return(type = S_QUOTES);
    else if (d == 60)
        return (type = L_DERECTION);
    else if (d == 62)
        return(type = R_DERECTION);
    else if (d == 36)
        return (type = DOLLAR);
    return(11);

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
  
t_cmd    *get_str(char *str, t_tokens token, t_cmd *cmd)
{
    int     i;
    int     j;
    char    *line;

    cmd = NULL;
    i = -1;
    j = 0;
    while (str[++i])
    {
         line = ft_strdup("");
        line[j++] = str[i];
        if (check_user_input(str[i], token) && check_user_input(str[i],token) != 11)
        {
            cmd = cmd_list(line, token);
            j = 0;
            i = 0;
        }
    }
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