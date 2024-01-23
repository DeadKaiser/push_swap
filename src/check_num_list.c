/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- <cosorio-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:26:45 by cosorio-          #+#    #+#             */
/*   Updated: 2024/01/23 16:11:59 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	check_num_list(int list_size, t_node **stack)
{
	t_node	*stack_b;
	t_node	*cheapest;
	int		size;
	t_node	*final_min;

	cheapest = NULL;
	stack_b = NULL;
	size = 0;
	if (list_size == 1)
		write(1, "Error\n", 6);
	else if (list_size == 2)
		is_sorted_2(*stack);
	else if (list_size == 3)
		sorted3(&(*stack));
	else
	{
		while (ft_lstsize(*stack) > 3)
			pb(&(*stack), &stack_b);
		sorted3(&(*stack));

		size = ft_lstsize(stack_b);
		while (size > 0)
		{

			get_target_node(*stack, stack_b);
			get_node_position_and_half(*stack);
			get_node_position_and_half(stack_b);
			get_cost(*stack);
			get_cost(stack_b);
			cheapest = get_cheapest(stack_b);
			move_nodes(cheapest, &(*stack), &stack_b);
			pa(&stack_b,&(*stack));
			size--;
		}
		//Función final para terminar de ordenar la lista.

		get_node_position_and_half(*stack);
		get_cost(*stack);
		final_min = get_min(*stack);
		if (final_min->upper_half)
		{
			while(final_min->cost > 0)
			{
				ra(stack);
				final_min->cost--;
			}
		}
		else
		{
			while(final_min->cost > 0)
			{
				rra(stack);
				final_min->cost--;
			}
		}
	}
	if (*stack)
		free_stack(&(*stack));
}
