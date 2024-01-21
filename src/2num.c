/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2num.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- <cosorio-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:27:27 by cosorio-          #+#    #+#             */
/*   Updated: 2024/01/21 15:52:18 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	is_sorted_2(t_node *list)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = list;
	tmp2 = list->next;
	if (tmp->value < tmp2->value)
		return ;
	else
		sa(&list);
}
