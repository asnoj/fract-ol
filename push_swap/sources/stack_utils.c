/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:55:28 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/11 01:24:24 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*stack_pop(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->top)
		return (NULL);
	stack->size--;
	node = stack->top;
	stack->top = stack->top->next;
	node->next = NULL;
	return (node);
}

int	stack_size(t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack->size);
}

int	is_stack_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size < 2)
		return (1);
	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

t_node	*get_node_n(t_stack *stack, int n)
{
	t_node	*current;
	int		i;

	if (!stack || n < 0 || n >= stack->size)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current && i < n)
	{
		current = current->next;
		i++;
	}
	return (current);
}

int	find_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack || !stack->top)
		return (0);
	min = stack->top->value;
	current = stack->top->next;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}
