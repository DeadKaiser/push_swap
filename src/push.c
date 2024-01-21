#include "../incl/push_swap.h"

void push_b(t_node **lst_a, t_node **lst_b)
{
    t_node *first_node;

    first_node = *lst_a;
    *lst_a = (*lst_a)->next;

    first_node->next = NULL;
    ft_lstadd_front(&(*lst_b), first_node);

}