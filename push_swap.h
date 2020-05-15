#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./Libft/libft.h"

typedef struct  s_stack
{
    int             data;
    int             no;
    struct s_stack  *next;
}                   t_stack;

typedef struct  s_lista
{
    t_stack         *a;
    t_stack         *b;
    int             fd;
    int             length;
    char            **array;
}               t_lista;

int         ft_lstlen(t_stack *n);
void        ft_freearray(int i, char **array);
void        ft_freemem(t_stack *mem);
int         raise(int a, int b);
void        push(t_stack **stack1, t_stack **stack2);
void        rotate(t_stack **stack);
void        rr(t_stack **stack);
void        rr2(t_lista *list);
int         swap(t_stack *stack);
int         se_high(t_lista *list);
int         find_list(t_lista *list, int length);
int         next_int(t_lista *list, int length, int n);
int         find_next_int(t_lista *list, int range, int length);
int         origin(t_lista *list);
void        sort_1(t_lista *list, int len);
void        sort_2(t_lista *list);
void        sort_3(t_lista *list);
void        set_tab(int *array, t_lista *list, size_t i);
int         locate(t_lista *list, size_t i);
int         int_sort(char *str, t_lista *list);
void        ft_freestack(t_lista *list);
int         int_checker(char *str);
int         filter_args(int argc, char *argv, t_lista *list);
int         args_checker(int argc, char **argv, t_lista *list);
int         valid_input(int argc, char **argv, t_lista *list);
int         m_swap(char *str, t_lista *list);
int         m_push(char *str, t_lista *list);
int         m_rotate(char *str, t_lista *list);
int         read_ps(t_lista *list);
t_stack     *check_sort(t_stack *stack, int (*i)(int, int));
t_stack     *ft_newintlist(void);

#endif