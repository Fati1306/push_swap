/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:43:51 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/24 17:33:45 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: ctr d when needs to check if sorted too

#include "checker_bonus.h"

#include <stdio.h>

void	print_list(t_node *lst)
{
	char	*str;

	if (lst)
	{
		printf("list:\n");
		while (lst != NULL)
		{
			str = ft_itoa((lst->data));
			printf("%s\n", str);
			free(str);
			lst = lst->next;
		}
	}
}

static void	find_instr_2(char **inst, char **p, t_node **a, t_node **b)
{
	if (ft_strcmp(*inst, "sa\n") == 0)
		sa_b(a, inst, p);
	else if (ft_strcmp(*inst, "sb\n") == 0)
		sb_b(b, inst, p);
	else if (ft_strcmp(*inst, "ss\n") == 0)
		ss_b(a, b, inst, p);
	else if (ft_strcmp(*inst, "pa\n") == 0)
		pa_b(a, b, inst, p);
	else if (ft_strcmp(*inst, "pb\n") == 0)
		pb_b(b, a, inst, p);
	else if (ft_strcmp(*inst, "ra\n") == 0)
		ra_b(a, inst, p);
	else if (ft_strcmp(*inst, "rb\n") == 0)
		rb_b(b, inst, p);
	else if (ft_strcmp(*inst, "rr\n") == 0)
		rr_b(a, b, inst, p);
	else if (ft_strcmp(*inst, "rra\n") == 0)
		rra_b(a, inst, p);
	else if (ft_strcmp(*inst, "rrb\n") == 0)
		rrb_b(b, inst, p);
	else if (ft_strcmp(*inst, "rrr\n") == 0)
		rrr_b(a, b, inst, p);
	else
		free_and_exit(2, inst, p);
}

static void	find_instruction(char **inst, char **p, t_node **a, t_node **b)
{
	if (ft_strcmp(*inst, "\n") == 0)
	{
		if (check_sorted_stack(*a) == 0 && !(*b))
			free_and_exit(0, inst, p);
		else
			free_and_exit(1, inst, p);
	}
	else
		find_instr_2(inst, p, a, b);
}

static void	read_instructions(t_node **a, t_node **b)
{
	char	*inst;
	char	*p;

	inst = ft_strdup("");
	p = NULL;
	p = (char *) malloc(sizeof(char));
	if (p == NULL || read(0, p, 0) == -1)
		exit(0);
	while (read(0, p, 1) > 0)
	{
		inst = ft_strjoin(inst, p);
		if (p[0] == '\n')
		{
			find_instruction(&inst, &p, a, b);
			free(inst);
			inst = ft_strdup("");
		}
	}
	if (check_sorted_stack(*a) == 0 && !(*b))
		free_and_exit(0, &inst, &p);
	else
		free_and_exit(1, &inst, &p);
}

int	main(int ac, char **av)
{
	t_node	*a_head;
	t_node	*b_head;
	char	**args;
	int		i;

	a_head = NULL;
	b_head = NULL;
	args = NULL;
	i = 0;
	if (ac == 2 && ft_strchr(av[1], ' ') != NULL)
		parse_av(&a_head, av, &args);
	else
	{
		check_args(ac, av, 0);
		if (ac <= 2)
			exit(0);
		init_stack_a(&a_head, ac, av, 1);
	}
	print_list(a_head);
	read_instructions(&a_head, &b_head);
	return (0);
}