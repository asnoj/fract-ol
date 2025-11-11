/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 00:14:55 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/11 00:53:24 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	ft_cmp_rr(t_stack *a, t_stack *b, char *inst)
{
	if (ft_strncmp(inst, "rra\n") == 0)
		rev_rota_bonus(a);
	if (ft_strncmp(inst, "rrb\n") == 0)
		rev_rota_bonus(b);
	if (ft_strncmp(inst, "rrr\n") == 0)
		rev_rotaa_bonus(a, b);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	t_node	*curr_a;
	t_node	*curr_b;

	ft_printf("\n    a          b\n ─────────────────────\n");
	curr_a = a->top;
	curr_b = b->top;
	while (curr_a || curr_b)
	{
		if (curr_a)
		{
			ft_printf("  %d    ", curr_a->value);
			curr_a = curr_a->next;
		}
		else
			ft_printf("          ");
		if (curr_b)
		{
			ft_printf("  %d", curr_b->value);
			curr_b = curr_b->next;
		}
		ft_printf("\n");
	}
	ft_printf(" ─────────────────────\n    a          b\n\n\n");
}

int	ft_add(int *argc, char **argv)
{
	if (*argc == 3)
	{
		if (!ft_strncmp(argv[2], "-p"))
		{
			argv[2][0] = '\0';
			(*argc)--;
			return (2);
		}
		else if (!ft_strncmp(argv[2], "-m"))
		{
			argv[2][0] = '\0';
			(*argc)--;
			return (1);
		}
		else if (!ft_strncmp(argv[2], "-moves"))
		{
			argv[2][0] = '\0';
			(*argc)--;
			return (3);
		}
	}
	return (0);
}

void	ft_print_if(t_stack *a, t_stack *b, int add, int c)
{
	if (add == 2 && c == 1)
	{
		write(1, "Before sort:\n", 13);
		print_stacks(a, b);
	}
	else if (add == 2 && c == 2)
	{
		write(1, "After sort:\n", 12);
		print_stacks(a, b);
	}
}

void	ft_aff_c(t_list *inst, int add)
{
	t_list	*current;

	current = inst;
	while (current->next)
		current = current->next;
	if (add == 1)
		ft_printf("moves = %d\n", current->i);
	if (add == 3)
	{
		current = inst->next;
		while (current)
		{
			printf("%s\n", current->instruction);
			current = current->next;
		}
	}
}
