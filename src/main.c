/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:49:04 by cosorio-          #+#    #+#             */
/*   Updated: 2024/01/24 12:20:29 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"


/* static void	ft_leaks()
{
	system("leaks push_swap");
}  */

void	check_aux(char **argv, int i, t_node **stack_a)
{
	char	**words;
	int		words_num;

	words = ft_split(argv[i], ' ');
	write(1, "Entra", 5);
	words_num = count_words(argv[i], ' ');
	write(1, "Entra", 5);
	check_input(words, words_num, &(*stack_a));
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	int		i;
	int		list_size;

	i = 1;
	stack_a = NULL;
	write(1, "Test", 4);
	//atexit(ft_leaks);
	while (i < argc)
	{
		check_aux(argv, i, &(stack_a));
		write(1, "EntraFinal", 10);
		if (!stack_a)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	if(stack_a)
	{
		list_size = ft_lstsize(stack_a);
		if (!is_duplicated(stack_a))
			check_num_list(list_size, &stack_a);
		return (0);
	}
	
}
