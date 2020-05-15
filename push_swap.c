#include "push_swap.h"

int main(int argc, char **argv)
{
    int         a;
    t_lista      *list;

    if (argc < 2)
        return (0);
    list = (t_lista *)ft_memalloc(sizeof(t_lista));
    a = valid_input(argc, argv, list);
    if (a)
    {
        ft_putstr_fd("Error\n", 2);
        if (list->array)
            ft_freearray(ft_lstlen(list->a), list->array);
        free(list);
        exit(0);
    }
    list->length = ft_lstlen(list->a);
    if (list->length >= 2 && list->length <= 3)
    {
        sort_2(list);
        ft_freestack(list);
    }
    if (check_sort(list->a, raise))
        exit(0);
    sort_1(list, list->length);
    ft_freestack(list);
}