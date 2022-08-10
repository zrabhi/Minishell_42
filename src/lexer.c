#include "../hedears/minishell.h"


int  ft_skip_space(char d)
{
    if (d == ' ')
        return(1);
    return(0);
}


/** satrting to check double_quotes_in echo cmd
 * still need to optimaze it more
 * it only workd in this case ("your_msg")
 * */
 
/**
 *  
 * check if the last caractere == to '"", if its not, you should display (quotes>) and the readline will waits for user to enter the last qoutes.
 * if (line[i] != '"")
 *      print:  syntax error
 * 
 * 
 * 
 * 
 * 
 * */


bool number_of_quotes(char *line) //---this fucntion return true if there is enough quotes to execute echo command
{
    int i;
    int quotes;

    i = -1;
    quotes = 0;
    while (line[++i])
    {
        if (line[i] == '\"')
            quotes++;       
    }
    if (quotes % 2 == 0)
        return(true);
    else 
        return (false);
}



char *double_quotes_check(char *line)
{
    printf("in double_quotes_func\n");
    int i;
    int j;
    char *str;
    
    i = 0;
    j = 0;

    str = ft_strdup("");
    while (line[i])
    {
        printf("in first_loop\n");
        if (line[i] == '\"' && line[i - 1] == ' ')
        {
            i++;    
            while (line[i] != '\"' )
            {
                printf("in double_quotes_loop\n");
                str[j] = line[i];
                j++;
                i++;
            }
            str[i] = '\0';
        }
        i++;
    }
    return (str);
}





int ft_pipe_check(char *line, t_tokens type)
{
    int i;
    char *cmd;
    // int j; 
    
    i = 0;
    // j = 0;
    printf("%c\n", line[0]);
    while (line[i])
    {
        printf("in pipe_check : \n");
        // if (ft_skip_space(line[i]))
        //     i++;
        if (check_user_input(line[i], type) == PIPE)
        { 
            type = PIPE;
    
            cmd = ft_substr(line, 0, i);
            printf("\n%s[WORD]", cmd);
            printf("\n PIPE [|]\n");
            i++;
        }       
        else if (check_user_input(line[i], type) == L_DERECTION)
        {
            type = L_DERECTION;
            printf("\n L_DERECTION---->[<]\n");
            i++;
        }
        i++;
    }
    free(cmd);
    return(0);
}
