/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:12:40 by cosorio-          #+#    #+#             */
/*   Updated: 2024/01/19 16:23:39 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp2 = (*stack);
	tmp = get_bottom(*stack);
	*stack = tmp2->next;
	tmp->next = tmp2;
	tmp2->next = NULL;
}

void	ra(t_node **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rb(t_node **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
