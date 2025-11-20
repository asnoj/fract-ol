/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:28:23 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/03 01:31:46 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!a || !b || !b->top)
		return ;
	node = stack_pop(b);
	stack_push(a, node);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!a || !b || !a->top)
		return ;
	node = stack_pop(a);
	stack_push(b, node);
	write(1, "pb\n", 3);
}
