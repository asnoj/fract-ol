/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 04:41:34 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/03 00:00:42 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	push_bonus(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!a || !b || !b->top)
		return ;
	node = stack_pop(b);
	stack_push(a, node);
}

void	swap_bonus(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (!b || b->size < 2)
		return ;
	first = b->top;
	second = b->top->next;
	first->next = second->next;
	second->next = first;
	b->top = second;
}

void	swapp_bonus(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (a && a->size >= 2)
	{
		first = a->top;
		second = a->top->next;
		first->next = second->next;
		second->next = first;
		a->top = second;
	}
	swap_bonus(b);
}

void	rota_bonus(t_stack *a)
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
}

void	rotaa_bonus(t_stack *a, t_stack *b)
{
	if (a && a->size >= 2)
	{
		rota_bonus(a);
	}
	if (b && b->size >= 2)
	{
		rota_bonus(b);
	}
}
