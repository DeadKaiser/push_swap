/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 00:15:37 by cosorio-          #+#    #+#             */
/*   Updated: 2024/01/24 11:08:24 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

long	ft_atol(const char *str)
{
	long	nbr;
	int		sign;
	size_t	i;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr * sign);
}

t_node	*get_bottom(t_node *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_node	*before_bottom(t_node *stack)
{
	while (stack && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}
