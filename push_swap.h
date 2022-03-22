/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:44:19 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/21 17:34:16 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_sort
{
	int		size;
	int		to_push;
	int		min;
	int		mid;
	int		max;
	int		index;
	int		push_side;
	int		last_n_index;
	t_node	*faked_node;
}	t_sort;

typedef struct s_instructions
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}	t_i;

void	ft_putstr(char *s);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strcmp(char *s1, char *s2);

void	error_exit(void);
void	init_i(t_i *i);

void	check_args(int ac, char **av);
int		check_sorted_stack(t_node *head);

t_node	*create_node(int data);
void	add_to_back(t_node **lst, t_node *new);
t_node	*last_node(t_node *lst);
int		last_node_index(t_node *lst);
void	print_list(t_node *lst);
void	free_list(t_node *list);
t_node	*before_last_node(t_node *lst);
void	index_stack(t_node **head);
int		find_smallest_index(t_node *lst);
int		list_size(t_node *lst);
int		index_of_node(t_node *lst, int data);
void	push_side(t_node *head, t_sort *s, int min, int max);
int		search_for_index(t_node **b_head, int index);

void	sa(t_node **a_head, t_i *i);
void	sb(t_node **b_head, t_i *i);
void	ss(t_node **a_head, t_node **b_head, t_i *i);
void	pa(t_node **a_head, t_node **b_head, t_i *i);
void	pb(t_node **b_head, t_node **a_head, t_i *i);
void	ra(t_node **a_head, t_i *i);
void	rb(t_node **b_head, t_i *i);
void	rr(t_node **a_head, t_node **b_head, t_i *i);
void	rra(t_node **a_head, t_i *i);
void	rrb(t_node **b_head, t_i *i);
void	rrr(t_node **a_head, t_node **b_head, t_i *i);
void	check_instructions(t_i *i, int check);

void	sort_three(t_node **head, t_i *i);
void	sort_four(t_node **a_head, t_node **b_head, t_i *i);
void	sort_five(t_node **a_head, t_node **b_head, t_i *i);
void	sort_six_plus(t_node **a_head, t_node **b_head, t_i *i);

#endif