/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:58:46 by ozini             #+#    #+#             */
/*   Updated: 2024/01/21 13:19:56 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	push(t_node **first_list, t_node **second_list)
{
	t_node	*first_node;

	first_node = *first_list;
	*first_list = (*first_list)->next;

	first_node->next = NULL;
	ft_lstadd_front(&(*second_list), first_node);
}

void	pb(t_node **first_list, t_node **second_list)
{
	push(&(*first_list), &(*second_list));
	write(1, "pb\n", 3);
}

void	pa(t_node **first_list, t_node **second_list)
{
	push(&(*first_list), &(*second_list));
	write(1, "pa\n", 3);
}