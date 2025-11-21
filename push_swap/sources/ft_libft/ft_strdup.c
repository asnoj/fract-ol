/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 02:22:22 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/02 01:49:34 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int	main(int ac, char **av)
// {
// 	if (ac < 2)
// 		return (1);
// 	printf("av1 = %s | strdup = %s\n", av[1], ft_strdup(av[1]));
// }
