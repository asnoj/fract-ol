/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:34:41 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/11 03:48:12 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	push_to_b(a, b);
	sort_three(a);
	push_to_a(a, b);
	final_rotation(a);
}

void	final_rotation(t_stack *a)
{
	int	min;

	min = find_min(a);
	while (a->top->value != min)
	{
		move_one_a(a, 1);
	}
}

void	push_to_b(t_stack *a, t_stack *b)
{
	int			value;
	t_stats		*stats;
	int			last_size;

	last_size = a->size;
	stats = calcul_stats(a);
	while (a->size > 3)
	{
		if (a->size <= last_size * 0.8)
			(free(stats), stats = calcul_stats(a));
		value = a->top->value;
		if (value >= stats->mediane && value <= stats->q3)
			pb(a, b);
		else if (value >= stats->q1 && value < stats->mediane)
		{
			pb(a, b);
			if (!check_swap_rota(a, b))
				rb(b);
		}
		else
			ra(a);
	}
	free(stats);
}

void	push_to_a(t_stack *a, t_stack *b)
{
	t_node	*cheapest;

	cheapest = NULL;
	while (b->top)
	{
		calcul_all_costs(a, b);
		cheapest = find_cheapest(b);
		move_cheapest(a, b, cheapest);
		pa(a, b);
	}
}

t_stats	*calcul_stats(t_stack *a)
{
	int		*tab;
	t_node	*current;
	int		i;
	t_stats	*stats;

	tab = malloc(a->size * sizeof(int));
	if (!tab)
		return (NULL);
	stats = malloc(1 * sizeof(t_stats));
	if (!stats)
		return (free(tab), NULL);
	i = 0;
	current = a->top;
	while (current)
	{
		tab[i++] = current->value;
		current = current->next;
	}
	ft_sort(tab, a->size);
	stats->q1 = tab[a->size / 4];
	stats->mediane = tab[a->size / 2];
	stats->q3 = tab[a->size * 3 / 4];
	return (free(tab), stats);
}
