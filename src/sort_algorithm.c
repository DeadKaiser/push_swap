/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:28:26 by ozini             #+#    #+#             */
/*   Updated: 2024/01/21 15:46:09 by ozini            ###   ########.fr       */
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

t_node *get_min(t_node *stack)
{
	int min;
	t_node *temp_min;

	min = INT_MAX;
	temp_min = NULL;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			temp_min = stack;
		}
		stack = stack ->next;
	}
	return (temp_min);
}

