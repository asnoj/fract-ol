/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:27:58 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/03 01:28:17 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	second = a->top->next;
	first->next = second->next;
	second->next = first;
	a->top = second;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
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
	write(1, "sb\n", 3);
}

void	sb_no_write(t_stack *b)
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

void	ss(t_stack *a, t_stack *b)
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
	sb_no_write(b);
	write(1, "ss\n", 3);
}
