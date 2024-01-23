/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- <cosorio-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:49:04 by cosorio-          #+#    #+#             */
/*   Updated: 2024/01/23 16:09:51 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"


/* static void	ft_leaks()
{
	system("leaks push_swap");
}  */

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	int		i;
	char	**words;
	int		words_num;
	int		list_size;

	i = 1;
	stack_a = NULL;

	//atexit(ft_leaks);
	
	while (i < argc)
	{
		words = ft_split(argv[i], ' ');
		words_num = count_words(argv[i], ' ');
		check_input(words, words_num, &(stack_a));
		if (!stack_a)
			return (0);
		i++;
	}
	list_size = ft_lstsize(stack_a);
	if (!is_duplicated(stack_a))
		check_num_list(list_size, &stack_a);
	else
		printf("Hay un duplicado");
	return (0);
}
