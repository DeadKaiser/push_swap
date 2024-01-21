/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 00:12:39 by cosorio-          #+#    #+#             */
/*   Updated: 2024/01/19 16:57:27 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	if ((*lst) == NULL)
	{
		(*lst) = new;
		return ;
	}
	while ((*lst)->next != NULL)
		lst = &(*lst)->next;
	(*lst)->next = new;
}


//ft_lstnew
t_node	*ft_lstnew(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->node_position = 0;
	new->cost = 0;
	new->cheapest = false;
	new->upper_half = false;
	new->target_node = NULL;
	new->next = NULL;
	return (new);
}

//ft_lstsize
int	ft_lstsize(t_node *lst)
{
	size_t	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
// stack_new
/* t_node	*stack_new(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->node_position = 0;
	new->cost = 0;
	new->cheapest = false;
	new->upper_half = false;
	new->target_node = NULL;
	//new->index = 0;
	new->next = NULL;
	return (new);
} */
//free stack
void	free_stack(t_node **stack)
{
	t_node	*tmp;

	//if (!stack || !(*stack))
	if (!(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
