#include "../hedears/minishell.h"
#include "../LIBFT/libft.h"

void    ft_shell(char **av)
{
    char   *path;
    t_cmd *cmd;
    char *line;
    
    (void)av;
    cmd = malloc(sizeof(t_cmd));
    if(!cmd)
        return ((void)NULL);
    t_tokens type;
    type = WORD;
    while (1)
    {
        path = readline("Minishell$ ");
        line = line_check(path);
        // if (!line)
        //     return(NULL);
        printf("command : %s\n", line);
        // // ft_pipe_check(path, type);
        // // printf("%s\n", path);
        // if(path)
        //     add_history(path);
        // if (number_of_quotes(path))
        //     line = double_quotes_check(path);
        // if (!line)
        //     {
        //         printf("SYNTAX ERROR\n");
        //         free(line);
        //         free(path);
        //         return ((void)NULL);
        //     }
        // else   
        //     printf("%s\n", line);
        // printf("%lu\n", ft_strlen(line));
        // ft_pipe_check(path, type);
        // printf("\n");
        free(path);
        free(line);
        system("leaks Minishell");
    }
}
