#include "push_swap.h"

void    set_tab(int *array, t_lista *list, size_t i)
{
    size_t      j;
    t_stack     *temp;

    temp = list->a;
    while (list->a != NULL)
    {
        j = 0;
        while (j < i)
        {
            if (array[j] == list->a->data)
                list->a->no = j;
            j++;
        }
        list->a = list->a->next;
    }
    list->a = temp;
}

int locate(t_lista *list, size_t i)
{
    int     *array;
    t_stack *temp;

    temp = list->a;
    array = (int *)malloc(sizeof(int) * i + 1);
    i = 0;
    while (list->a != NULL)
    {
        array[i] = list->a->data;
        i++;
        list->a = list->a->next;
    }
    if (ft_swaptab(array, i))
    {
        free(array);
        return (0);
    }
    list->a = temp;
    set_tab(array, list, i);
    free(array);
    return (1);
}

int int_sort(char *str, t_lista *list)
{
    int i;

    i = 0;
    list->array = ft_split(str);
    while (list->array[i] != NULL)
    {
        if (ft_atoi(list->array[i]) < -214748368 || ft_atoi(list->array[i]) > 214748367)
            return (1);
        if (list->array[i + 1] != NULL)
            list->a->next = ft_newintlist();
        list->a->data = (ft_atoi(list->array[i]));
        list->a = list->a->next;
        i++;
    }
    return (0);
}