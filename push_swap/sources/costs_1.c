/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:37:48 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/01 23:45:36 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	calcul_opti_cost(t_node *node)
{
	int	cost_a;
	int	cost_b;

	cost_a = node->cost_a;
	cost_b = node->cost_b;
	if (cost_a > 0 && cost_b > 0)
		return (max(cost_a, cost_b));
	if (cost_a < 0 && cost_b < 0)
		return (max(abs(cost_a), abs(cost_b)));
	return (abs(cost_a) + abs(cost_b));
}

// int	max(int	a, int b)
// {
// 	int	i;

// 	if (b < 0 && a < 0)
// 	{
// 		b *= -1;
// 		a *= -1;
// 	}
// 	i = 0;
// 	while (i > b || i > a)
// 		i++;
// 	if (b > a)
// 		return (i + b - a);
// 	if (b < a)
// 		return (i + a - b);
// 	return (i);
// }

// int	calcul_opti_cost(t_node *current)
// {
// 	int	cost_a;
// 	int	cost_b;

// 	cost_a = current->cost_a;
// 	cost_b = current->cost_b;
// 	if (current->cost_a > 0 && current->cost_b > 0)
// 		return (max(current->cost_a, current->cost_b));
// 	else if (current->cost_a < 0 && current->cost_b < 0)
// 		return (max(current->cost_a, current->cost_b));
// 	else
// 	{
// 		if (cost_a < 0)
// 			cost_a *= -1;
// 		if (cost_b < 0)
// 			cost_b *= -1;
// 		return (cost_a + cost_b);
// 	}
// }
