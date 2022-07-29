#include "../hedears/minishell.h"
//-------------- starting the parsing part -------------------------------------------
int main(int ac, char **av)
{
    (void)ac;
    ft_shell(av);
}
// #include <stdio.h>
// #include <readline/readline.h>
// #include <readline/history.h>
// # include <stdlib.h>

// int main(void)
// {
// 	char *a;

// 	a = readline("input :");
// 	printf("%d\n" ,rl_on_new_line());
// 	printf("%s\n", a);
// 	printf("%d\n" ,rl_on_new_line());
// 	free(a);
// }