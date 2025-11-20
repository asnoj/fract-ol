/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:31:40 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/11 01:56:42 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	char	**strs_arg;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (1);
	strs_arg = parse_arguments(argc, argv);
	if (!strs_arg)
		return (ft_putendl_fd("Error", 1), 1);
	a = ft_strs_to_stack(strs_arg);
	if (!a)
		return (ft_putendl_fd("Error", 1), 1);
	if (is_stack_sorted(a))
		return (ft_free_tab(a, NULL, strs_arg), 0);
	b = stack_new();
	if (!b)
		return (free(a), ft_putendl_fd("Error", 1), 1);
	ft_check_stack_small(a, b);
	if (is_stack_sorted(a))
		return (ft_free_tab(a, b, strs_arg), 0);
	push_swap(a, b);
	ft_free_tab(a, b, strs_arg);
}
