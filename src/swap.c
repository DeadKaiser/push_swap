/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- <cosorio-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 13:51:46 by cosorio-          #+#    #+#             */
/*   Updated: 2024/01/24 13:38:36 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

static void	swap(t_node **stack)
{
	t_node	*tmp;
	t_node	*tmp2;
	int		tmp_value;

	if (!*stack || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	tmp2 = tmp->next;
	tmp_value = tmp->value;
	tmp->value = tmp2->value;
	tmp2->value = tmp_value;
}

void	sa(t_node **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_node **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
