#include "push_swap.h"

int         m_swap(char *str, t_lista *list)
{
    if (ft_strcmp(str, "sa") == 0)
        swap(list->a);
    else if (ft_strcmp(str, "sb") == 0)
        swap(list->b);
    else if (ft_strcmp(str, "ss") == 0)
    {
        swap(list->a);
        swap(list->b);
    } 
    else
        return (0);
    return (1);
}

int         m_push(char *str, t_lista *list)
{
    if (ft_strcmp(str, "pa") == 0)
        push(&list->b, &list->a);
    else if (ft_strcmp(str, "pb") == 0)
        push(&list->a, &list->b);
    else 
        return (0);
    return (1);
}

int         m_rotate(char *str, t_lista *list)
{
    if (ft_strcmp(str, "ra") == 0)
        rotate(&list->a);
    else if (ft_strcmp(str, "rb") == 0)
        rotate(&list->b);
    else if (ft_strcmp(str, "rr") == 0)
    {
        rotate(&list->a);
        rotate(&list->b);
    }
    else if (ft_strcmp(str, "rra") == 0)
        rr(&list->a);
    else if (ft_strcmp(str, "rrb") == 0)
        rr(&list->b);
    else if (ft_strcmp(str, "rrr") == 0)
    {
        rr(&list->a);
        rr(&list->b);
    }
    else
        return (0);
    return (1);
}

int         read_ps(t_lista *list)
{
    int     i;
    int     j;
    char    *str;

    i = 0;
    while ((j = get_next_line(list->fd, &str) > 0))
    {
        if (ft_strchr(str, 's'))
            i = m_swap(str, list);
        else if (ft_strchr(str, 'p'))
            i = m_push(str, list);
        else if (ft_strchr(str, 'r'))
            i = m_rotate(str, list);
        else
            return (1);
        if (i == 0)
        {
            free(str);
            return (1);
        }
    }
    return (0);
}