/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 02:54:43 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/11 04:02:33 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_tab(t_stack *a, t_stack *b, char **strs)
{
	if (a)
		ft_free_stack(a);
	if (b)
		ft_free_stack(b);
	if (strs)
		ft_free_strs(strs);
}

void	ft_free_stack(t_stack *s)
{
	t_node	*current;
	t_node	*temp;

	current = s->top;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(s);
}

void	ft_free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**ft_free_arg(char **strs)
{
	size_t	i;

	i = 0;
	if (!strs)
		return (NULL);
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}
