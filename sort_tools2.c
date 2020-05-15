#include "push_swap.h"

int     se_high(t_lista *list)
{
    int     i;
    t_stack *temp;

    i = 0;
    temp = list->b;
    while (list->b)
    {
        if (list->b->no > i)
            i = list->b->no;
        list->b = list->b->next;
    }
    list->b = temp;
    return (i);
}

int     find_list(t_lista *list, int length)
{
    int i;

    i = ft_lstlen(list->b);
    while (ft_lstlen(list->b) - i <= (length / 5))
    {
        if (list->a->no >= (length - (length / 5)))
        {
            push(&list->a, &list->b);
            ft_putstr("pb\n");
        }
        else
        {
            if (find_next_int(list, length, (length / 5)) == 1)
            {
                while (!(list->a->no >= (length - (length / 5))))
                {
                    rotate(&list->a);
                    ft_putstr("ra\n");
                }
            }
            else
            {
                while (!(list->a->no >= (length - (length / 5))))
                {
                    rr(&list->a);
                    ft_putstr("rra\n");
                }
            }
        }
    }
    return (1);
}

int     next_int(t_lista *list, int length, int n)
{
    int     i;
    t_stack *temp;

    i = 0;
    temp = list->b;
    while (temp != NULL)
    {
        if (temp->no == n)
        {
            if (i > (length / 2))
                return (0);
            return (1);
        }
        i++;
        temp = temp->next;
    }
    return (1);
}

int     find_next_int(t_lista *list, int range, int length)
{
    int     i;
    t_stack *temp;

    i = 0;
    temp = list->a;
    while (temp)
    {
        if (temp->no >= (length - range))
            if (i >= length / 2)
                return (0);
        i++;
        temp = temp->next;
    }
    return (1);
}

int     origin(t_lista *list)
{
    int i;

    i = se_high(list);
    while (ft_lstlen(list->b) > 0)
    {
        if (list->b->no == i)
        {
            push(&list->b, &list->a);
            ft_putstr("pa\n");
            i--;
        }
        else if (next_int(list, ft_lstlen(list->b), i) == 0)
        {
            while (list->b->no != i)
            {
                rr(&list->b);
                ft_putstr("rrb\n");
            }
        }
        else
        {
            while (list->b->no != i)
            {
                rotate(&list->b);
                ft_putstr("rb\n");
            }
        }
    }
    return (1);
}