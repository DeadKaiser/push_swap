/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- <cosorio-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:56:01 by cosorio-          #+#    #+#             */
/*   Updated: 2024/01/24 13:30:05 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_list
{
	int				value;
	int				node_position;
	int				cost;
	bool			upper_half;
	bool			cheapest;
	struct t_list	*target_node;
	struct t_list	*next;
}					t_node;

void				check_input(char **str, int words_num, t_node **stack);
int					higher_cost(t_node *cheapest, int *lower_cost);
int					ft_lstsize(t_node *lst);
t_node				*ft_lstnew(int value);
void				ft_lstadd_back(t_node **lst, t_node *new);
long				ft_atol(const char *str);
void				is_sorted_2(t_node *list);
void				sa(t_node **stack_a);
void				sb(t_node **stack_a);
void				ss(t_node **stack_a, t_node **stack_b);
void				rotate(t_node **stack_a);
t_node				*get_bottom(t_node *stack);
void				ra(t_node **stack);
void				rb(t_node **stack);
void				rr(t_node **stack_a, t_node **stack_b);
t_node				*before_bottom(t_node *stack);
void				reverse_rotate(t_node **stack);
void				rrb(t_node **stack);
void				rra(t_node **stack);
void				rrr(t_node **stack_a, t_node **stack_b);
void				sorted3(t_node **stack);
void				free_stack(t_node **stack);
size_t				ft_strlen(const char *s);
int					is_duplicated(t_node *list);
char				**ft_split(char const *s, char c);
size_t				count_words(char const *s, char c);
void				check_num_list(int list_size, t_node **stack);
void				check_aux(char **argv, int i, t_node **stack_a);
void				sorted_n(t_node **stack, t_node *stack_b);
void				push(t_node **first_list, t_node **second_list);
void				pa(t_node **first_list, t_node **second_list);
void				pb(t_node **first_list, t_node **second_list);
void				ft_lstadd_front(t_node **lst, t_node *new);
void				get_target_node(t_node *stack_a, t_node *stack_b);
t_node				*get_min(t_node *stack);
void				get_node_position_and_half(t_node *stack);
void				get_cost(t_node *stack);
t_node				*get_cheapest(t_node *stack_b);
t_node				*get_init(t_node **stack_a, t_node *stack_b);
void				move_nodes(t_node *cheapest, t_node **stack_a,
						t_node **stack_b);
void				polish_off(t_node **stack);
void				both_nodes_upper_half(t_node *cheapest, t_node **stack_a,
						t_node **stack_b);
void				both_nodes_lower_half(t_node *cheapest, t_node **stack_a,
						t_node **stack_b);

#endif