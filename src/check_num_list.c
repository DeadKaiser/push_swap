/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- <cosorio-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:26:45 by cosorio-          #+#    #+#             */
/*   Updated: 2024/01/21 15:49:13 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	check_num_list(int list_size, t_node **stack)
{
	t_node	*a;
	t_node	*stack_b;

	stack_b = NULL;
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
		get_target_node(*stack, stack_b);
	}
	a = *stack;
/* 	while ((*stack))
	{
		printf("El valor de la lista es %d\n", (*stack)->value);
		(*stack) = (*stack)->next;
	}
	while ((stack_b))
	{
		printf("El valor de la lista es %d y su target node es %d\n", (stack_b)->value, stack_b->target_node->value);
		(stack_b) = (stack_b)->next;
	} */
	if (a)
		free_stack(&a);
}
