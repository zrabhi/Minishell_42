#include "../hedears/minishell.h"

t_list *creat_node(char *content)
{printf("in create node");
      
    t_list *lst;
    lst = malloc(sizeof(t_list));
    if (!lst)
        return(NULL);
    lst->content = content;
    lst->next = NULL;
    lst->previous = NULL;
    return(lst); 
}

void    ft_creat_lst(t_data **data, t_list *lst)
{
    t_list *tmp;

    if((*data))
    {
        if (!(*data)->list_head)
        {
            (*data)->list_head = lst;
            (*data)->list_tail = lst;
            (*data)->list_head->next = NULL;
            (*data)->list_head->previous = (*data)->list_tail;
        }
        else
        {
            tmp = (*data)->list_head;
            (*data)->list_head = lst;
            (*data)->list_head->previous = (*data)->list_tail;
            lst->next = tmp;
            tmp->previous = (*data)->list_head;
            (*data)->list_tail->next = NULL;
        }
    }
}
