/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:35:57 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/11 04:16:29 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"

typedef struct s_stats
{
	int				q1;
	int				mediane;
	int				q3;
}					t_stats;

typedef struct s_stack
{
	struct s_node	*top;
	int				size;
}					t_stack;

typedef struct s_node
{
	int				value;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}					t_node;

// algo push swap

void				push_swap(t_stack *a, t_stack *b);
void				push_to_b(t_stack *a, t_stack *b);
void				push_to_a(t_stack *a, t_stack *b);
void				final_rotation(t_stack *a);
t_stats				*calcul_stats(t_stack *a);
void				move_one_a(t_stack *a, int cost);

// costs

void				calcul_all_costs(t_stack *a, t_stack *b);
void				calcul_cost_node(t_node *node, t_stack *a, t_stack *b,
						int pos_b);
int					calcul_rota_cost(int pos, int size);
int					find_pos_aimed(int value, t_stack *a);
int					calcul_opti_cost(t_node *current);
t_node				*find_cheapest(t_stack *b);
void				move_cheapest(t_stack *a, t_stack *b, t_node *cheapest);

// sort

void				sort_two(t_stack *a);
void				sort_three(t_stack *a);

// operations

void				rrb_no_write(t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

// stack

t_node				*stack_pop(t_stack *stack);
int					stack_size(t_stack *stack);
t_node				*get_node_n(t_stack *stack, int n);
int					find_min(t_stack *stack);
int					find_max(t_stack *stack);
int					find_min_position(t_stack *stack);
int					is_stack_sorted(t_stack *stack);
t_node				*node_new(int value);
t_stack				*stack_new(void);
void				stack_push(t_stack *stack, t_node *node);
void				creat_stack_from_nbr(t_stack *stack, char **nbrs);
t_stack				*ft_strs_to_stack(char **strs_arg);
int					check_swap_rota(t_stack *a, t_stack *b);
void				ft_check_stack_small(t_stack *a, t_stack *b);
int					find_min_index(t_stack *stack);

// idk

char				**ft_free_arg(char **strs);
char				**parse_arguments(int argc, char **argv);
int					ft_is_argv_all_int(char **strs);
int					is_in_int_range(char *str);
int					has_duplicates(char **numbers);
char				**ft_split(char const *s, char c);
int					ft_strncmp(const char *s1, const char *s2);
void				ft_sort(int *tab, int size);
void				print_stacks(t_stack *a, t_stack *b);
char				**ft_strsdup(char **strs);
int					ft_tablen(char **tab);
int					ft_strncmp(const char *s1, const char *s2);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_strdup(const char *s);
int					ft_isdigit(int c);
size_t				ft_strlen(const char *s);
int					ft_atoi(const char *nptr);
int					ft_strcmp_pars(const char *s1, const char *s2);
void				push_min_to_b(t_stack *a, t_stack *b);

// free

void				ft_free_stack(t_stack *s);
void				ft_free_strs(char **strs);
void				ft_free_tab(t_stack *a, t_stack *b, char **strs);

#endif