/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 03:49:49 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/11 04:11:45 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "push_swap.h"
# include <fcntl.h>
# include "../bonus/get_next_line/get_next_line.h"
# include "ft_printf.h"

typedef struct s_list
{
	struct s_list	*next;
	char			*instruction;
	int				i;
}	t_list;

long	ft_atol(const char *nptr);
int		is_in_int_range(char *str);
int		has_duplicates(char **numbers);
char	**ft_free_arg(char **strs);
char	*ft_strdup(const char *s);
t_stack	*ft_strs_to_stack(char **strs_arg);
void	creat_stack_from_nbr(t_stack *stack, char **nbrs);

void	ft_cmp_rr(t_stack *a, t_stack *b, char *inst);
int		ft_is_argv_all_int(char **strs);
char	**parse_arguments_checker(int argc, char **argv);
size_t	ft_strlen(const char *s);
void	ft_free_strs(char **strs);
void	ft_putendl_fd(char const *s, int fd);
void	ft_free_tab(t_stack *a, t_stack *b, char **strs);
void	ft_free_stack(t_stack *s);
t_stack	*stack_new(void);
void	ft_putendl_fd(char const *s, int fd);
t_node	*stack_pop(t_stack *stack);
void	ft_free_list(t_list *list);
void	push_bonus(t_stack *a, t_stack *b);
void	swap_bonus(t_stack *b);
void	swapp_bonus(t_stack *a, t_stack *b);
void	rota_bonus(t_stack *a);
void	rotaa_bonus(t_stack *a, t_stack *b);
void	rev_rota_bonus(t_stack *a);
void	rev_rotaa_bonus(t_stack *a, t_stack *b);
void	print_stacks(t_stack *a, t_stack *b);
int		ft_add(int *argc, char **argv);
void	ft_print_if(t_stack *a, t_stack *b, int add, int c);
void	ft_aff_c(t_list *inst, int add);

#endif