/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:11:14 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/02 03:46:28 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t			i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

// int	main(int ac, char **av)
// {
// 	if (ac < 4)
// 		return (1);
// 	int ptr = ft_strncmp(av[1], av[2], ft_atoi(av[3]));
// 	printf("%d\n", ptr);
// }
