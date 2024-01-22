/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:26:45 by cosorio-          #+#    #+#             */
/*   Updated: 2024/01/22 15:50:04 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	check_num_list(int list_size, t_node **stack)
{
	t_node	*a;
	t_node	*stack_b;
	t_node	*cheapest;
	int		size;
	t_node *b;


	
	cheapest = NULL;
	stack_b = NULL;
	a = NULL;
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

			//printf("tamaño de lista A; %d\n",ft_lstsize(*stack));
			printf("\n");
			get_target_node(*stack, stack_b);
			get_node_position_and_half(*stack);
			get_node_position_and_half(stack_b);
			get_cost(*stack);
			get_cost(stack_b);
			cheapest = get_cheapest(stack_b);
			b = stack_b;
			a = *stack;
			while(a)
			{
				printf("El valor de la lista es %d y su posicion es %d\n", (a)->value, (a)->node_position);
				a = a -> next;
			}
			 while (b)
			{
				printf("el numero es %d, su posición es %d y su upper_half %d , el target node es : %d y su coste del nodo es %d y de su target node el coste es %d", (b)->value, (b)->node_position, (b) ->upper_half, (b) -> target_node-> value, (b) ->cost , (b) -> target_node -> cost);
				(b) = (b)->next;
			} 
			move_nodes(cheapest, &(*stack), &stack_b);
			pa(&stack_b,&(*stack));

			printf("\n");
			if (size == 1)
			{
				a = *stack;
				while(a)
				{
					printf("El valor de la lista es %d y su posicion es %d\n", (a)->value, (a)->node_position);
					a = a -> next;
				}
			}
			/* while (b)
			{
				printf("el numero es %d, el target node es : %d y su coste del nodo es %d y de su target node el coste es %d", (b)->value,(b) -> target_node-> value, (b) ->cost , (b) -> target_node -> cost);
				(b) = (b)->next;
			}  */
			size--;
		}
	}

	/* 	while ((*stack))
		{
			printf("El valor de la lista es %d\n", (*stack)->value);
			(*stack) = (*stack)->next;
		} */
	/*while ((stack_b))
	{
		printf("El valor de la lista es %d y su target node es %d\n",
			(stack_b)->value, stack_b->target_node->value);
		(stack_b) = (stack_b)->next;
	} */
/* 	while (a)
	{
		//printf("El valor de la lista A es %d, la posición es %d y el upper half es %d\n", (*stack)->value,
		//	(*stack)->node_position, (*stack)->upper_half);
			printf("valor :%d\n", (a) ->value);
		(a) = (a)->next;
	} */
/* 	while ((stack_b))
	{
		printf("El valor de la lista B es %d, la posición es %d,el upper half es %d y el coste es %d\n", (stack_b)->value,
			(stack_b)->node_position, (stack_b)->upper_half, (stack_b)->cost);
		(stack_b) = (stack_b)->next;
	} */
	//printf("El valor del cheapest es el número %d y su coste es %d",
		//cheapest->value, (cheapest->cost + cheapest->target_node->cost));
	if (a)
		free_stack(&a);
}
