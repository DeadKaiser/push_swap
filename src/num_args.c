/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- <cosorio-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:55:29 by cosorio-          #+#    #+#             */
/*   Updated: 2024/01/23 16:56:08 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	is_sorted_2(t_node *list)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = list;
	tmp2 = list->next;
	if (tmp->value < tmp2->value)
		return ;
	else
		sa(&list);
}

void	sorted3(t_node **stack)
{
	if ((*stack)->value > (*stack)->next->value
		&& (*stack)->value > (*stack)->next->next->value)
		ra(stack);
	else if ((*stack)->next->value > (*stack)->value
		&& (*stack)->next->value > (*stack)->next->next->value)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	polish_off(t_node **stack)
{
	t_node	*final_min;

	get_node_position_and_half(*stack);
	get_cost(*stack);
	final_min = get_min(*stack);
	if (final_min->upper_half)
	{
		while (final_min->cost > 0)
		{
			ra(stack);
			final_min->cost--;
		}
	}
	else
	{
		while (final_min->cost > 0)
		{
			rra(stack);
			final_min->cost--;
		}
	}
}

void sorted_n(t_node **stack, t_node *stack_b)
{
	t_node	*cheapest;
	int		size;

	while (ft_lstsize(*stack) > 3)
		pb(&(*stack), &stack_b);
	sorted3(&(*stack));
	size = ft_lstsize(stack_b);
	while (size > 0)
	{
		cheapest = get_init(stack, stack_b);
		move_nodes(cheapest, &(*stack), &stack_b);
		pa(&stack_b, &(*stack));
		size--;
	}
	polish_off(stack);
    
}
