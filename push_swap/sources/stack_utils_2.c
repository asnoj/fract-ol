/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:47:41 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/11 04:09:38 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_swap_rota(t_stack *a, t_stack *b)
{
	t_node	*na;
	t_node	*nb;

	na = a->top->next;
	nb = b->top->next;
	if (((a->top > na) && (na < get_node_n(a, a->size)))
		&& ((b->top > nb) && (nb < get_node_n(b, b->size))))
	{
		ss(a, b);
		return (1);
	}
	else if ((a->top > na) && (na < get_node_n(a, a->size)))
	{
		sa(a);
		return (1);
	}
	else if ((b->top > nb) && (nb < get_node_n(b, b->size)))
	{
		sb(b);
		return (1);
	}
	return (0);
}

int	find_min_index(t_stack *stack)
{
	int		min_val;
	int		min_index;
	int		i;
	t_node	*current;

	current = stack->top;
	min_val = stack->top->value;
	min_index = 0;
	i = 1;
	while (i < stack->size)
	{
		if (current->value < min_val)
		{
			min_val = current->value;
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	min_val;
	int	min_index;
	int	size;

	size = a->size;
	min_val = find_min(a);
	min_index = find_min_position(a);
	if (min_index <= size / 2)
	{
		while (a->top->value != min_val)
			ra(a);
	}
	else
	{
		while (a->top->value != min_val)
			rra(a);
	}
	pb(a, b);
}
