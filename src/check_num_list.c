/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:26:45 by cosorio-          #+#    #+#             */
/*   Updated: 2024/01/24 10:59:03 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	check_num_list(int list_size, t_node **stack)
{
	t_node	*stack_b;
	t_node	*cheapest;
	int		size;

	cheapest = NULL;
	stack_b = NULL;
	size = 0;
	if (list_size == 1)
		return;
	else if (list_size == 2)
		is_sorted_2(*stack);
	else if (list_size == 3)
		sorted3(&(*stack));
	else
		sorted_n(stack, stack_b);
	if (*stack)
		free_stack(&(*stack));
}
