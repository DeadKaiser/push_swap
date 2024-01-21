/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:26:45 by cosorio-          #+#    #+#             */
/*   Updated: 2024/01/21 16:52:03 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	check_num_list(int list_size, t_node **stack)
{
	t_node	*a;
	t_node	*stack_b;
	t_node	*cheapest;

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
		get_node_position_and_half(*stack);
		get_node_position_and_half(stack_b);
		get_cost(*stack);
		get_cost(stack_b);
		cheapest = get_cheapest(stack_b);

		
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
	while ((*stack))
	{
		printf("El valor de la lista es %d, la posición es %d y el upper half es %d\n", (*stack)->value, (*stack)->node_position, (*stack)->upper_half);
		(*stack) = (*stack)->next;
	}
	while ((stack_b))
	{
		printf("El valor de la lista es %d, la posición es %d, el upper half es %d y el coste es %d\n", (stack_b)->value, (stack_b)->node_position, (stack_b)->upper_half, (stack_b)->cost);
		(stack_b) = (stack_b)->next;
	}
	printf("El valor del cheapest es el número %d y su coste es %d", cheapest->value, (cheapest->cost + cheapest->target_node->cost));
	if (a)
		free_stack(&a);
}
