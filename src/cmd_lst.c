#include "../hedears/minishell.h"


t_cmd *cmd_list(char *str, t_tokens token)
{
    t_cmd *cmd;

    cmd = malloc(sizeof(t_cmd));
    if (!cmd)
        return (false);
    cmd->cmdline = str;
    cmd->type = token;
    cmd->next = NULL;
}
