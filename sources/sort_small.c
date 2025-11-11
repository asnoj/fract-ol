/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:29:19 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/11 04:09:31 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_five(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	min_index;

	if (a->size != 4)
		return ;
	min_index = find_min_index(a);
	if (min_index == 1)
		ra(a);
	else if (min_index == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_index == 3)
		rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	ft_check_stack_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	if (a->size == 3)
		sort_three(a);
	if (a->size == 4)
		sort_four(a, b);
	if (a->size == 5)
		sort_five(a, b);
}

void	sort_two(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (!a)
		return ;
	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && first > third && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && first > third && second < third)
		ra(a);
	else if (first > second && first < third && second < third)
		sa(a);
	else if (first < second && first > third && second > third)
		rra(a);
	else if (first < second && first < third && second > third)
	{
		sa(a);
		ra(a);
	}
}
