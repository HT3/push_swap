#include "push_swap.h"

void    sort_2(t_lista *list)
{
    while (!check_sort(list->a, raise))
    {
        if (list->a->no == 2)
        {
            rotate(&list->a);
            ft_putstr("ra\n");
        }
        else if (list->a->no < list->a->next->no)
        {
            rr(&list->a);
            ft_putstr("rra\n");
        }
        else if (list->a->no > list->a->next->no)
        {
            swap(list->a);
            ft_putstr("sa\n");
        }
    }
}

void    sort_3(t_lista *list)
{
    while (ft_lstlen(list->a) > 3)
    {
        if (find_next_int(list, 1, ft_lstlen(list->a)) == 0)
        {
            while (list->a->no > 1)
            {
                rotate(&list->a);
                ft_putstr("ra\n");
            }
            push(&list->a, &list->b);
            ft_putstr("pb\n");
        }
        else
        {
            while (list->a->no > 1)
            {
                rr(&list->a);
                ft_putstr("rra\n");
            }
            push(&list->a, &list->b);
            ft_putstr("pb\n");
        }
    }
    sort_2(list);
    origin(list);
}

void    sort_1(t_lista *list, int len)
{
    if (ft_lstlen(list->a) == 5)
    {
        sort_3(list);
        exit(0);
    }
    while (ft_lstlen(list->a) >= 5)
    {
        find_list(list, len - 1);
        len = ft_lstlen(list->a);
    }
    while (list->a->no != 3)
    {
        rotate(&list->a);
        ft_putstr("ra\n");
    }
    ft_putstr("pb\n");
    push(&list->a, &list->b);
    sort_2(list);
    origin(list);
    rr2(list);
}