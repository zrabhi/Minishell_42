#include "../hedears/minishell.h"
#include "../LIBFT/libft.h"

void    ft_shell(char **av)
{
    char   *path;
    t_cmd *cmd;
    char *line= NULL;
    
    (void)av;
    cmd = malloc(sizeof(t_cmd));
    if(!cmd)
        return ((void)NULL);
    t_tokens type;
    type = WORD;
    while (1)
    {
        path = readline("Minishell$ ");
        cmd  = get_str(path, type, cmd);
        add_history(path);
        free(path);
        free(line);
        system("leaks Minishell");
    }
}
