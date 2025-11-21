/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:28:40 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/03 01:39:49 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_stack *a)
{
	t_node	*first;
	t_node	*current;

	if (!a || a->size < 2)
		return ;
	first = stack_pop(a);
	a->size++;
	current = a->top;
	while (current->next)
		current = current->next;
	current->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	t_node	*first;
	t_node	*current;

	if (!b || b->size < 2)
		return ;
	first = stack_pop(b);
	b->size++;
	current = b->top;
	while (current->next)
		current = current->next;
	current->next = first;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	rb_nowr(t_stack *b)
{
	t_node	*first;
	t_node	*current;

	if (!b || b->size < 2)
		return ;
	first = stack_pop(b);
	b->size++;
	current = b->top;
	while (current->next)
		current = current->next;
	current->next = first;
	first->next = NULL;
}

void	rr(t_stack *a, t_stack *b)
{
	t_node	*first_a;
	t_node	*current_a;

	if (a && a->size >= 2)
	{
		first_a = stack_pop(a);
		a->size++;
		current_a = a->top;
		while (current_a->next)
			current_a = current_a->next;
		current_a->next = first_a;
		first_a->next = NULL;
	}
	if (b && b->size >= 2)
		rb_nowr(b);
	write(1, "rr\n", 3);
}
