/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 03:04:56 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/11 04:10:01 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**ft_strsdup(char **strs)
{
	char	**strs_duped;
	int		i;
	int		j;

	j = 0;
	i = 0;
	strs_duped = malloc((ft_tablen(strs) + 1) * sizeof(char *));
	if (strs_duped == NULL)
		return (NULL);
	while (strs[i])
	{
		strs_duped[j] = ft_strdup(strs[i]);
		i++;
		j++;
	}
	strs_duped[j] = NULL;
	return (strs_duped);
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

void	ft_sort(int *tab, int size)
{
	int	i;
	int	tmp;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[i])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	find_min_position(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		pos;
	int		i;

	if (!stack || !stack->top)
		return (-1);
	min = stack->top->value;
	pos = 0;
	i = 0;
	current = stack->top;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			pos = i;
		}
		current = current->next;
		i++;
	}
	return (pos);
}

int	ft_strcmp_pars(const char *s1, const char *s2)
{
	size_t			i;
	size_t			j;

	j = 0;
	i = 0;
	while (s1[i] || s2[j])
	{
		if (s1[i] == '+')
			i++;
		if (s2[j] == '+')
			j++;
		if (s1[i] - s2[j] != 0)
			return (s1[i] - s2[j]);
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}
