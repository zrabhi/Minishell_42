#include "../hedears/minishell.h"
#include "../libft/libft.h"

void    ft_shell(char **av)
{
    char   *path;
    t_cmd *cmd;
    (void)av;
    cmd = malloc(sizeof(t_cmd));
    if(!cmd)
        return ((void)NULL);
    t_tokens type;
    type = WORD;
    while(1)
    {
           path = readline("Minishell$ ");
            ft_pipe_check(path, type);
        printf("%s\n", path);
        if(path)
            add_history(path);
        if (number_of_quotes(path))
            printf("function is working\n");
        else
            printf("function  is not working\n");
        line = double_quotes_check(path, cmd);
        if (!line)
            {
                printf("SYNTAX ERROR\n");
                free(line);
                return ((void)NULL);
            }
        else   
            printf("%s\n", line);
        printf("%lu\n", ft_strlen(line));
        ft_pipe_check(path, type);
        printf("\n");
        free(path);
        // free(line);
        system("leaks Minishell");
    }
}
