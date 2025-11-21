/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_free_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 04:27:17 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/08 20:21:25 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	ft_free_list(t_list *list)
{
	t_list	*current;

	current = list;
	while (current)
	{
		list = list->next;
		free(current->instruction);
		free(current);
		current = list;
	}
	free(list);
}
