#include "push_swap.h"

int         main(int argc, char **argv)
{
    int     a;
    t_lista *list;

    if (argc <= 1)
        return (0);
    list = (t_lista *)ft_memalloc(sizeof(t_lista));
    list->length = 0;
    a = valid_input(argc, argv, list);
    if (a)
    {
        ft_putstr_fd("Error\n", 2);
        exit(0);
    }
    if (read_ps(list))
    {
        ft_putstr_fd("Error\n", 2);
        exit(0);
    }
    if (!check_sort(list->a, raise) || ft_lstlen(list->b) > 0)
    {
        ft_putstr_fd("KO\n", 2);
        exit(0);
    }
    ft_putstr_fd("OK\n", 2);
    exit(1);
}