/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_opp_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 04:49:54 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/02 01:03:11 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	rev_rota_bonus(t_stack *a)
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
}

void	rev_rotaa_bonus(t_stack *a, t_stack *b)
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
		rev_rota_bonus(b);
}
