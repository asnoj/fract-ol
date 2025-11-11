/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 03:52:34 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/11 04:11:12 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

t_list	*lst_new(char *instruction, int i)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->next = NULL;
	list->i = i;
	list->instruction = ft_strdup(instruction);
	return (list);
}

t_list	*ft_take_all_inst(void)
{
	t_list	*list;
	t_list	*current;
	char	*line;
	int		i;

	i = 0;
	list = lst_new("start", i++);
	if (!list)
		return (NULL);
	current = list;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		current->next = lst_new(line, i++);
		if (!current->next)
		{
			ft_free_list(list);
			return (NULL);
		}
		free(line);
		current = current->next;
	}
	return (list);
}

void	ft_move_stacks(t_stack *a, t_stack *b, t_list *inst, int add)
{
	t_list	*current_inst;

	(ft_print_if(a, b, add, 1), current_inst = inst->next);
	while (current_inst)
	{
		if (ft_strncmp(current_inst->instruction, "pa\n") == 0)
			push_bonus(a, b);
		if (ft_strncmp(current_inst->instruction, "pb\n") == 0)
			push_bonus(b, a);
		if (ft_strncmp(current_inst->instruction, "sa\n") == 0)
			swap_bonus(a);
		if (ft_strncmp(current_inst->instruction, "sb\n") == 0)
			swap_bonus(b);
		if (ft_strncmp(current_inst->instruction, "ss\n") == 0)
			swapp_bonus(a, b);
		if (ft_strncmp(current_inst->instruction, "ra\n") == 0)
			rota_bonus(a);
		if (ft_strncmp(current_inst->instruction, "rb\n") == 0)
			rota_bonus(b);
		if (ft_strncmp(current_inst->instruction, "rr\n") == 0)
			rotaa_bonus(a, b);
		ft_cmp_rr(a, b, current_inst->instruction);
		current_inst = current_inst->next;
	}
	ft_print_if(a, b, add, 2);
}

int	ft_check_stack(t_stack *a, t_stack *b)
{
	t_node	*a_n;
	int		value;

	a_n = a->top;
	if (!a_n)
		return (1);
	if (b->top)
		return (1);
	value = a_n->value;
	a_n = a_n->next;
	while (a_n)
	{
		if (value > a_n->value)
			return (1);
		value = a_n->value;
		a_n = a_n->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	**strs;
	t_stack	*a;
	t_stack	*b;
	t_list	*inst;
	int		add;

	if (argc < 2)
		return (1);
	add = ft_add(&argc, argv);
	strs = parse_arguments_checker(argc, argv);
	if (!strs)
		return (ft_putendl_fd("Error", 1), 1);
	a = ft_strs_to_stack(strs);
	if (!a)
		return (1);
	inst = ft_take_all_inst();
	if (!inst)
		return (ft_free_tab(a, NULL, strs), ft_putendl_fd("Error", 1), 1);
	b = stack_new();
	if (!b)
		return (ft_free_tab(a, NULL, strs), ft_free_list(inst), 1);
	(ft_move_stacks(a, b, inst, add), ft_aff_c(inst, add));
	if (ft_free_list(inst), ft_check_stack(a, b))
		return (ft_free_tab(a, b, strs), ft_putendl_fd("K0", 1), 1);
	return (ft_free_tab(a, b, strs), ft_putendl_fd("OK", 1), 1);
}
