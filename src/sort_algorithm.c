/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:28:26 by ozini             #+#    #+#             */
/*   Updated: 2024/01/21 15:40:10 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	get_target_node(t_node *stack_a, t_node *stack_b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;
	t_node	*target_node;
	int		closest;
	int		i;

	i = 1;
	tmp_b = stack_b;
	while (tmp_b)
	{
		target_node = NULL;
		closest = INT_MAX;
		tmp_a = stack_a;
		while (tmp_a != NULL)
		{
			//printf("Bucle %d", i);
			i++;
			if (tmp_b->value < tmp_a->value && tmp_a->value < closest)
			{
				closest = tmp_a->value;
				target_node = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (!target_node)
		{
			//printf("Entra");
			target_node = get_min(stack_a);
		}
		//else
		tmp_b->target_node = target_node;
		//printf("El target node es %d", tmp_b->target_node->value);
		tmp_b = tmp_b->next;
	}

}

t_node *get_min(t_node *stack)
{
	int min;
	t_node *temp_min;
	t_node *t;

	min = INT_MAX;
	temp_min = NULL;
	t = stack;
	while (t)
	{
		//printf("El nodo de A vale %d\n", t->value);
		if (t->value < min)
		{
			min = t->value;
			temp_min = t;
		}
		t = t ->next;
	}
	return (temp_min);
}

