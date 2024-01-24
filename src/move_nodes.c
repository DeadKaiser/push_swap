/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- <cosorio-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:11:07 by cosorio-          #+#    #+#             */
/*   Updated: 2024/01/24 13:45:19 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	higher_cost(t_node *cheapest, int *lower_cost)
{
	int	j;

	j = 0;
	if (cheapest->cost > cheapest->target_node->cost)
	{
		*lower_cost = cheapest->target_node->cost;
		j = cheapest->cost;
	}
	else
	{
		*lower_cost = cheapest->cost;
		j = cheapest->target_node->cost;
	}
	return (j);
}

void	both_nodes_upper_half(t_node *cheapest, t_node **stack_a,
		t_node **stack_b)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = higher_cost(cheapest, &i);
	x = j - i;
	while (i--)
		rr(stack_a, stack_b);
	while (x > 0 && j == cheapest->cost)
	{
		rb(stack_b);
		x--;
	}
	while (x > 0 && (j == cheapest->target_node->cost))
	{
		ra(stack_a);
		x--;
	}
}

void	both_nodes_lower_half(t_node *cheapest, t_node **stack_a,
		t_node **stack_b)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = higher_cost(cheapest, &i);
	x = j - i;
	while (i--)
		rrr(stack_a, stack_b);
	while (x > 0 && j == cheapest->cost)
	{
		rrb(stack_b);
		x--;
	}
	while (x > 0 && (j == cheapest->target_node->cost))
	{
		rra(stack_a);
		x--;
	}
}

void	move_nodes(t_node *cheapest, t_node **stack_a, t_node **stack_b)
{
	int	i;

	i = 0;
	if (cheapest->upper_half && cheapest->target_node->upper_half)
		both_nodes_upper_half(cheapest, stack_a, stack_b);
	else if ((cheapest->upper_half == false)
		&& (cheapest->target_node->upper_half == false))
		both_nodes_lower_half(cheapest, stack_a, stack_b);
	else
	{
		if (cheapest->upper_half)
			while ((cheapest->cost - i++) > 0)
				rb(stack_b);
		else
			while ((cheapest->cost - i++) > 0)
				rrb(stack_b);
		i = 0;
		if (cheapest->target_node->upper_half && cheapest->upper_half == false)
			while ((cheapest->target_node->cost - i++) > 0)
				ra(stack_a);
		else
			while ((cheapest->target_node->cost - i++) > 0)
				rra(stack_a);
	}
}
