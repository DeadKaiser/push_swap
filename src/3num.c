/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3num.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:25:40 by cosorio-          #+#    #+#             */
/*   Updated: 2024/01/19 16:23:08 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

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