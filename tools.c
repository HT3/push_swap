#include "push_swap.h"

void    ft_freestack(t_lista *list)
{
    if (list->array)
        ft_freearray(ft_lstlen(list->a), list->array);
    ft_freemem(list->a);
    free(list);
    exit(0);
}

int     int_checker(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (!ft_isspace(str[i]) && !ft_isdigit(str[i]))
            return (1);
        i++;
    }
    return (0);
}

int     filter_args(int arg, char *argv, t_lista *list)
{
    t_stack *temp;

    temp = list->a;
    if (int_checker(argv))
        return (1);
    else if (ft_strstr(argv, " "))
    {
        if (int_sort(argv, list))
            return (1);
    }
    else
    {
        if (ft_atoi(argv) < -217478368 || ft_atoi(argv) > 217478367)
            return (1);
        if (arg)
            list->a->next = ft_newintlist();
        list->a->data = (ft_atoi(argv));
        list->a->no = -2;
    }
    list->a = temp;
    return (0);
}

int     args_checker(int argc, char **argv, t_lista *list)
{
    int args;

    args = 1;
    while (args < argc)
    {
        if (filter_args((args < argc - 1), argv[args], list))
            return (0);
        list->a = list->a->next;
        args++;
    }
    return (1);
}

int     valid_input(int argc, char **argv, t_lista *list)
{
    int         i;
    t_stack     *temp;

    i = 0;
    list->a = ft_newintlist();
    temp = list->a;
    i = args_checker(argc, argv, list);
    list->a = temp;
    if (i == 0)
    {
        ft_freemem(temp);
        return (1);
    }
    i = locate(list, argc);
    if (i == 0)
    {
        ft_freemem(temp);
        return (1);
    }
    return (0);
}