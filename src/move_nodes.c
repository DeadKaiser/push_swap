/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:11:07 by cosorio-          #+#    #+#             */
/*   Updated: 2024/01/23 11:31:27 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	move_nodes(t_node *cheapest, t_node **stack_a, t_node **stack_b)
{
	int i;
	int j;
    int x;
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
			i = cheapest->cost; // -3 cost 0
			j = cheapest->target_node->cost; // 9 cost 1
		}
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
        x = j - i;
		while (i--)
			rrr(stack_a, stack_b);
		while (x > 0 && j == cheapest->cost)
		{
			rrb(stack_b);
			x--;
		}
		while (x > 0 && j == cheapest->target_node->cost)
		{
			rra(stack_a);
			x--;
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
		i = 0;
		if (cheapest->target_node->upper_half && cheapest->upper_half == false)
		{
			//if(cheapest->value == 49)
			printf("El coste del target de 49 (50) es %d y el valor de i es %d", cheapest->target_node->cost, i);
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
    