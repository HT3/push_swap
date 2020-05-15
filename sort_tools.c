#include "push_swap.h"

void        push(t_stack **stack1, t_stack **stack2)
{
    t_stack *s1;
    t_stack *s2;

    if (ft_lstlen(*stack1) < 1)
        return;
    s1 = *stack1;
    s2 = *stack1;
    s2 = s2->next;
    s1->next = NULL;
    s1->next = *stack2;
    *stack2 = s1;
    *stack1 = s2;
}

void        rotate(t_stack **stack)
{
    t_stack *list;
    t_stack *temp;

    if (ft_lstlen(*stack) <= 1)
        return;
    list = *stack;
    *stack = (*stack)->next;
    temp = list;
    while (temp->next != NULL)
        temp = temp->next;
    list->next = NULL;
    temp->next = list;
}

void        rr(t_stack **stack)
{
    t_stack *list;
    t_stack *temp;

    if (ft_lstlen(*stack) <= 1)
        return;
    list = *stack;
    temp = *stack;
    while (list->next->next != NULL)
        list = list->next;
    temp = list;
    list = list->next;
    temp->next = NULL;
    list->next = *stack;
    *stack = list;
}

void        rr2(t_lista *list)
{
    while (!(check_sort(list->a, raise)))
    {
        rr(&list->a);
        ft_putstr("rra\n");
    }
}

int         swap(t_stack *stack)
{
    if (stack == NULL || stack->next == NULL)
        return (1);
    if (ft_lstlen(stack) <= 1)
        return (1);
    ft_swap(&stack->data, &stack->next->data);
    ft_swap(&stack->no, &stack->next->no);
    return (0);
}

int         raise(int a, int b)
{
    return (a <= b);
}

t_stack     *check_sort(t_stack *stack, int (*i)(int, int))
{
    while (stack->next != 0)
    {
        if ((*i)(stack->data, stack->next->data) == 0)
            return (0);
        else
            stack = stack->next;
    }
    return (stack);
}