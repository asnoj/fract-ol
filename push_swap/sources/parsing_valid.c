/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:32:54 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/11 04:06:06 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**parse_arguments(int argc, char **argv)
{
	char	**strs_arg;

	strs_arg = NULL;
	if (argv[1][0] == '\0')
		return (NULL);
	if (argc > 2 && ft_is_argv_all_int(&argv[1]) && has_duplicates(&argv[1]))
		return (ft_strsdup(&argv[1]));
	if ((!ft_is_argv_all_int(&argv[1])
			|| !has_duplicates(&argv[1])) && argc > 2)
		return (NULL);
	if (argc == 2)
		strs_arg = ft_split(argv[1], ' ');
	if (!ft_is_argv_all_int(strs_arg) || !has_duplicates(strs_arg))
		return (ft_free_arg(strs_arg), NULL);
	return (strs_arg);
}

int	ft_is_argv_all_int(char **strs)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (strs[i])
	{
		if (!is_in_int_range(strs[i]))
			return (0);
		while (strs[i][j])
		{
			if (j == 0 && (strs[i][j] == '-' || strs[i][j] == '+'))
				j++;
			if (!ft_isdigit(strs[i][j]))
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!nptr)
		return (0);
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

int	is_in_int_range(char *str)
{
	long	num;

	if (!str || *str == '\0')
		return (0);
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int	has_duplicates(char **numbers)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (ft_strcmp_pars(numbers[i], numbers[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
