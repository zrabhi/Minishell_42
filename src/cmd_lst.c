#include "../hedears/minishell.h"


// t_cmd *cmd_list(char *str, t_tokens token, t_cmd *cmd)
// {
//     t_cmd *tmp;


//     tmp = cmd;
//     //  while(tmp)
//     //      tmp = tmp->next;
//     tmp = malloc(sizeof(t_cmd));
//     if (!cmd)
//         return (false);
//     tmp->str = str;
//     tmp->type = token;
//     tmp->next = NULL;
//     // if(!cmd->next)
//     //     cmd->next = tmp;
//     // printf("%s\n", cmd->str);
//     return (tmp);
// }


t_cmd *cmd_list(char *str, t_tokens token)
{
    t_cmd *new_node;
    t_cmd *cmd = NULL;
    t_cmd *tmp;

    new_node = malloc(sizeof(t_cmd));
    if(!new_node)
        return(NULL) ;
    new_node->str = str;
    new_node->type = token;
    new_node->next = NULL;
    if(!cmd)
        cmd = new_node;
    else{
            tmp = cmd;
            while(tmp->next)
                tmp = tmp->next;
            tmp->next = new_node; 
        }
    return (cmd);
}


void    print_lst(t_cmd *cmd)
{
    printf("commands part : \n");
    t_cmd *tmp;

    tmp = cmd;
    while (tmp)
    {
        printf("%s---->[%d]\n", tmp->str, tmp->type);
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
