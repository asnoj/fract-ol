/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:56:59 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/03 01:37:40 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_one_b(t_stack *b, int cost)
{
	if (cost > 0)
	{
		while (cost > 0)
		{
			rb(b);
			cost--;
		}
	}
	else if (cost < 0)
	{
		while (cost < 0)
		{
			rrb(b);
			cost++;
		}
	}
}

void	move_one_a(t_stack *a, int cost)
{
	if (cost > 0)
	{
		while (cost > 0)
		{
			ra(a);
			cost--;
		}
	}
	else if (cost < 0)
	{
		while (cost < 0)
		{
			rra(a);
			cost++;
		}
	}
}

void	move_both(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b);
		cost_a++;
		cost_b++;
	}
	if (cost_a != 0)
		move_one_a(a, cost_a);
	if (cost_b != 0)
		move_one_b(b, cost_b);
}

void	move_cheapest(t_stack *a, t_stack *b, t_node *cheapest)
{
	int	cost_a;
	int	cost_b;

	cost_a = cheapest->cost_a;
	cost_b = cheapest->cost_b;
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
		move_both(a, b, cost_a, cost_b);
	else
	{
		move_one_a(a, cost_a);
		move_one_b(b, cost_b);
	}
}

// void	move_one_b(t_stack *b, int cost)
// {
// 	int	signe;

// 	signe = 1;
// 	if (cost < 0)
// 	{
// 		cost *= -1;
// 		signe = -1;
// 	}
// 	while (cost > 0 && signe == 1)
// 	{
// 		rb(b);
// 		cost--;
// 	}
// 	while (cost > 0 && signe == -1)
// 	{
// 		rrb(b);
// 		cost--;
// 	}
// }

// void	move_one_a(t_stack *a, int cost)
// {
// 	int	signe;

// 	signe = 1;
// 	if (cost < 0)
// 	{
// 		cost *= -1;
// 		signe = -1;
// 	}
// 	while (cost > 0 && signe == 1)
// 	{
// 		ra(a);
// 		cost--;
// 	}
// 	while (cost > 0 && signe == -1)
// 	{
// 		rra(a);
// 		cost--;
// 	}
// }

// void	move_both(t_stack *a, t_stack *b, int cost_a, int cost_b)
// {
// 	int	signe;

// 	signe = 1;
// 	if (cost_a < 0 && cost_b < 0)
// 	{
// 		signe = -1;
// 		cost_a *= -1;
// 		cost_b *= -1;
// 	}
// 	while ((cost_a > 0 && cost_b > 0) && signe == 1)
// 	{
// 		rr(a, b);
// 		cost_a--;
// 		cost_b--;
// 	}
// 	while ((cost_a > 0 && cost_b > 0) && signe == -1)
// 	{
// 		rrr(a, b);
// 		cost_a--;
// 		cost_b--;
// 	}
// 	if (cost_a != 0)
// 		move_one_a(a, cost_a);
// 	if (cost_b != 0)
// 		move_one_b(b, cost_b);
// }
