/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 00:31:44 by cosorio-          #+#    #+#             */
/*   Updated: 2024/01/19 16:24:25 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	check_input(char **str, int words_num, t_node **stack)
{
	int		i;
	int		j;

	j = 0;
	while (j < words_num)
	{
		i = 0;
		if ((str[j][i] == '-' || str[j][i] == '+') && (ft_strlen(str[j]) > 1))
			i++;
		while (str[j][i] != '\0')
		{
			if (str[j][i] < '0' || str[j][i] > '9')
			{
				free_stack (stack);
				(*stack) = NULL;
				return ;
			}
			i++;
		}
		ft_lstadd_back(stack, ft_lstnew(ft_atoi(str[j])));
		free(str[j]);
		j++;
	}
	free(str);
}

int	is_duplicated(t_node *list)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = list;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
