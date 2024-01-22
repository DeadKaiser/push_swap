/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- <cosorio-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:28:26 by ozini             #+#    #+#             */
/*   Updated: 2024/01/22 15:00:06 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	get_target_node(t_node *stack_a, t_node *stack_b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;
	t_node	*target_node;
	int		closest;

	tmp_b = stack_b;
	while (tmp_b)
	{
		closest = INT_MAX;
		tmp_a = stack_a;
		while (tmp_a != NULL)
		{
			if (tmp_b->value < tmp_a->value && tmp_a->value < closest)
			{
				closest = tmp_a->value;
				target_node = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (closest == INT_MAX)
			target_node = get_min(stack_a);
		tmp_b->target_node = target_node;
		tmp_b = tmp_b->next;
	}
}

t_node	*get_min(t_node *stack)
{
	int		min;
	t_node	*temp_min;

	min = INT_MAX;
	temp_min = NULL;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			temp_min = stack;
		}
		stack = stack->next;
	}
	return (temp_min);
}

void	get_node_position_and_half(t_node *stack)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(stack);
	
	while (stack)
	{	
		if ((i <= (size / 2) && (size % 2) != 0))
			stack->upper_half = true;
		else
			stack->upper_half = false;
		stack->node_position = i++;
		stack = stack->next; 
	}
	

}

void	get_cost(t_node *stack)
{
	int size;

	size = ft_lstsize(stack);
	while(stack)
	{
		if(stack->upper_half)
			stack->cost = stack->node_position;
		else
			stack->cost = size - stack->node_position;
		stack = stack->next;
	}
}

t_node	*get_cheapest(t_node *stack_b)
{
	int		cheapest;
	int		costs;
	t_node	*cheapest_node;

	cheapest_node = stack_b;
	cheapest = (stack_b->cost) + (stack_b->target_node->cost);
	stack_b = stack_b->next;
	while (stack_b)
	{
		costs = stack_b->cost + stack_b->target_node->cost;
		if (costs < cheapest)
		{
			cheapest = costs;
			cheapest_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (cheapest_node);
}
