/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:28:59 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/03 04:24:00 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_stack *a)
{
	t_node	*current;
	t_node	*before_last;
	t_node	*last;

	if (!a || a->size < 2)
		return ;
	current = a->top;
	before_last = NULL;
	while (current->next)
	{
		before_last = current;
		current = current->next;
	}
	last = current;
	before_last->next = NULL;
	last->next = a->top;
	a->top = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	t_node	*current;
	t_node	*before_last;
	t_node	*last;

	if (!b || b->size < 2)
		return ;
	current = b->top;
	before_last = NULL;
	while (current->next)
	{
		before_last = current;
		current = current->next;
	}
	last = current;
	before_last->next = NULL;
	last->next = b->top;
	b->top = last;
	write(1, "rrb\n", 4);
}

void	rrb_no_write(t_stack *b)
{
	t_node	*current;
	t_node	*before_last;
	t_node	*last;

	if (!b || b->size < 2)
		return ;
	current = b->top;
	before_last = NULL;
	while (current->next)
	{
		before_last = current;
		current = current->next;
	}
	last = current;
	before_last->next = NULL;
	last->next = b->top;
	b->top = last;
}

void	rrr(t_stack *a, t_stack *b)
{
	t_node	*current_a;
	t_node	*before_last_a;
	t_node	*last_a;

	if (a && a->size >= 2)
	{
		current_a = a->top;
		before_last_a = NULL;
		while (current_a->next)
		{
			before_last_a = current_a;
			current_a = current_a->next;
		}
		last_a = current_a;
		before_last_a->next = NULL;
		last_a->next = a->top;
		a->top = last_a;
	}
	if (b && b->size >= 2)
		rrb_no_write(b);
	write(1, "rrr\n", 4);
}
