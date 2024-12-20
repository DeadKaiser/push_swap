/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 00:43:22 by cosorio-          #+#    #+#             */
/*   Updated: 2024/01/19 16:23:29 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	reverse_rotate(t_node **stack)
{
	t_node  *tmp;
	t_node  *tmp2;

	tmp = get_bottom(*stack);
	tmp2 = before_bottom(*stack);
	tmp->next = (*stack);
	(*stack) = tmp;
	tmp2->next = NULL;
}

void    rra(t_node **stack)
{
    reverse_rotate(stack);
    write(1,"rra\n",4);
}

void    rrb(t_node **stack)
{
    reverse_rotate(stack);
    write(1,"rrb\n",4);
}

void    rrr(t_node **stack_a, t_node **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    write(1,"rrr\n",4);
}