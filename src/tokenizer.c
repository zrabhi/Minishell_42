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
        printf("\033[0;31m UNXPECTED TOKEN\n");
        return(11);
    }
}

// int  ft_skip_space(char d)
// {
//     if (d == ' ')
//         return(1);
//     return(0);
// }

// int ft_pipe_check(char *line, t_tokens type)
// {
//     printf("in pipe_check : \n");
//     int i;
//     char *cmd;
//     int j; 
    
//     i = 0;
//     j = 0;
//     while (line[i])
//     {
//         if (check_user_input(line[i], type) == PIPE)
//         { 
//             type = PIPE;
//             cmd = ft_substr(line, 0, i);
//             printf("\n%s[WORD]", cmd);
//             printf("\n PIPE [|]\n");
//             i++;
//         }       
//         else if(check_user_input(line[i], type) == L_DERECTION)
//         {
//             type = L_DERECTION;
//             printf("\n L_DERECTION---->[<]\n");
//             i++;
//         }
//         i++;
//     }
//     return(0);
// }

