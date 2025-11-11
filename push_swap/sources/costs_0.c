/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:06:04 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/03 01:36:40 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*find_cheapest(t_stack	*b)
{
	t_node	*cheapest;
	int		min_cost;
	t_node	*current;
	int		cost;

	min_cost = INT_MAX;
	current = b->top;
	cheapest = NULL;
	while (current)
	{
		cost = calcul_opti_cost(current);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}

int	find_pos_aimed(int value, t_stack *a)
{
	int		aimed_pos;
	int		bigger_t_v;
	t_node	*current;
	int		pos;

	bigger_t_v = INT_MAX;
	pos = 0;
	current = a->top;
	aimed_pos = -1;
	while (current)
	{
		if (current->value > value && current->value < bigger_t_v)
		{
			bigger_t_v = current->value;
			aimed_pos = pos;
		}
		current = current->next;
		pos++;
	}
	if (aimed_pos == -1)
		return (find_min_position(a));
	return (aimed_pos);
}

int	calcul_rota_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (-(size - pos));
}

void	calcul_cost_node(t_node *node, t_stack *a, t_stack *b, int pos_b)
{
	int	pos_aimed;

	node->cost_b = calcul_rota_cost(pos_b, b->size);
	pos_aimed = find_pos_aimed(node->value, a);
	node->cost_a = calcul_rota_cost(pos_aimed, a->size);
}

void	calcul_all_costs(t_stack *a, t_stack *b)
{
	t_node	*current;
	int		pos_b;

	current = b->top;
	pos_b = 0;
	while (current)
	{
		calcul_cost_node(current, a, b, pos_b);
		current = current->next;
		pos_b++;
	}
}
