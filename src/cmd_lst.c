#include "../hedears/minishell.h"


t_cmd *cmd_list(char *str, t_tokens token)
{
    t_cmd *cmd;

    cmd = malloc(sizeof(t_cmd));
    if (!cmd)
        return (false);
    cmd->str = str;
    cmd->type = token;
    cmd->next = NULL;
    return (cmd);
}

void    print_lst(t_cmd *cmd)
{
    printf("commands part : \n");
    t_cmd *tmp;

    tmp = cmd;
    while (tmp)
    {
        printf("%s\n", tmp->str);
        tmp = tmp->next;
    }
    printf("\n");
}

void    print_tokens(t_cmd *cmd)
{
    printf("tokens part : \n");
    t_cmd *tmp;

    tmp = cmd;
    while(tmp)
    {
        printf("%d\n", tmp->type);
        tmp = tmp->next;
    }
    printf("\n");
}
