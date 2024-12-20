/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- <cosorio-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:49:04 by cosorio-          #+#    #+#             */
/*   Updated: 2024/01/24 13:38:15 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	check_aux(char **argv, int i, t_node **stack_a)
{
	char	**words;
	int		words_num;

	words = ft_split(argv[i], ' ');
	words_num = count_words(argv[i], ' ');
	check_input(words, words_num, &(*stack_a));
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	int		i;
	int		list_size;

	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		check_aux(argv, i, &(stack_a));
		if (!stack_a)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	if (stack_a)
	{
		list_size = ft_lstsize(stack_a);
		if (!is_duplicated(stack_a))
			check_num_list(list_size, &stack_a);
		return (0);
	}
}
