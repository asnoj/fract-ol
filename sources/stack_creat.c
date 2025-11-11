/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:47:27 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/05 17:46:04 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*stack_new(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(1 * sizeof(t_stack));
	if (!stack)
	{
		ft_putendl_fd("Error", 1);
		return (NULL);
	}
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*node_new(int value)
{
	t_node	*node;

	node = (t_node *)malloc(1 * sizeof(t_node));
	if (!node)
	{
		ft_putendl_fd("Error", 1);
		return (NULL);
	}
	node->value = value;
	node->cost_a = 0;
	node->cost_b = 0;
	node->next = NULL;
	return (node);
}

void	stack_push(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

void	creat_stack_from_nbr(t_stack *stack, char **nbrs)
{
	int		i;
	t_node	*node;

	if (!stack || !nbrs)
		return ;
	i = 0;
	while (nbrs[i])
		i++;
	while (i-- > 0)
	{
		node = node_new(ft_atoi(nbrs[i]));
		if (!node)
			return ;
		stack_push(stack, node);
	}
}

t_stack	*ft_strs_to_stack(char **strs_arg)
{
	t_stack	*a;

	a = stack_new();
	if (!a)
		return (NULL);
	creat_stack_from_nbr(a, strs_arg);
	return (a);
}
