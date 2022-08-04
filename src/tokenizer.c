#include "../hedears/minishell.h"

int check_user_input(char d, t_tokens type)
{
   if (d == 124)
       return (type = PIPE);
    else if (d == 34)
        return(type = D_QUOTES);
    else if (d == 39)
        return(type = QUOTES);
    else if (d == 60)
        return (type = L_DERECTION);
    else if (d == 62)
        return(type = R_DERECTION);
    else if (d == 36)
        return (type = DOLLAR);
    else{
        // printf("\033[0;31m UNXPECTED TOKEN\n");
        return(11);
    }
}

// im going to store a linked  
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