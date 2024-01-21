/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2num.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:27:27 by cosorio-          #+#    #+#             */
/*   Updated: 2024/01/19 16:25:44 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	is_sorted_2(t_node *list)
{
	t_node *tmp;
	t_node *tmp2;

	tmp = list;
	tmp2 = list->next;

	if (tmp->value < tmp2->value)
		return ;
	else
		sa(&list);
}