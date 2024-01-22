/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- <cosorio-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:11:07 by cosorio-          #+#    #+#             */
/*   Updated: 2024/01/22 11:48:45 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	move_nodes(t_node *cheapest, t_node **stack_a, t_node **stack_b)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (cheapest->upper_half && cheapest->target_node->upper_half)
	{
		if (cheapest->cost > cheapest->target_node->cost)
		{
			i = cheapest->target_node->cost;
			j = cheapest->cost;
		}
		else
		{
			i = cheapest->cost;
			j = cheapest->target_node->cost;
		}
		while (i--)
			rr(stack_a, stack_b);
		while ((j - i > 0) && j == cheapest->cost)
		{
			rb(stack_b);
			i++;
		}
		while ((j - i > 0) && j == cheapest->target_node->cost)
		{
			ra(stack_a);
			i++;
		}
	}
	else if ((cheapest->upper_half == false)
		&& (cheapest->target_node->upper_half == false))
	{
		if (cheapest->cost > cheapest->target_node->cost)
		{
			i = cheapest->target_node->cost;
			j = cheapest->cost;
		}
		else
		{
			i = cheapest->cost;
			j = cheapest->target_node->cost;
		}
		while (i--)
			rrr(stack_a, stack_b);
		while ((j - i > 0) && j == cheapest->cost)
		{
			rrb(stack_b);
			i++;
		}
		while ((j - i > 0) && j == cheapest->target_node->cost)
		{
			rra(stack_a);
			i++;
		}
	}
	else
	{
		if (cheapest->upper_half)
		{
			while ((cheapest->cost - i) > 0)
			{
				rb(stack_b);
				i++;
			}
		}
		else
		{
			while ((cheapest->cost - i) > 0)
			{
				rrb(stack_b);
				i++;
			}
		}
		if (cheapest->target_node->upper_half)
		{
			while ((cheapest->target_node->cost - i) > 0)
			{
				ra(stack_a);
				i++;
			}
		}
		else
		{
			while ((cheapest->target_node->cost - i) > 0)
			{
				rra(stack_a);
				i++;
			}
		}
	}
}


/* while(size = ft_listsize(stack_b) > 0)
    get_init(stack_a, stack_b)
    move_node;
    pa(nodo_b);
    size--; */
    