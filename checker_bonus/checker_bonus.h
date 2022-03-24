/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:35:06 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/24 17:31:02 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

void	error_exit(void);
void	free_and_exit(int x, char **inst, char **p);

void	check_args(int ac, char **av, int check);
int		check_sorted_stack(t_node *list);

int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
void	parse_av(t_node **a_head, char **av, char ***args);

t_node	*create_node(int data);
void	init_stack_a(t_node **a_head, int ac, char **av, int check);
void	add_to_back(t_node **lst, t_node *new);
t_node	*before_last_node(t_node *lst);
t_node	*last_node(t_node *lst);

void	pa_b(t_node **a_head, t_node **b_head, char **inst, char **p);
void	pb_b(t_node **b_head, t_node **a_head, char **inst, char **p);
void	sa_b(t_node **a_head, char **inst, char **p);
void	sb_b(t_node **b_head, char **inst, char **p);
void	ss_b(t_node **a_head, t_node **b_head, char **inst, char **p);
void	ra_b(t_node **a_head, char **inst, char **p);
void	rb_b(t_node **b_head, char **inst, char **p);
void	rr_b(t_node **a_head, t_node **b_head, char **inst, char **p);
void	rra_b(t_node **a_head, char **inst, char **p);
void	rrb_b(t_node **b_head, char **inst, char **p);
void	rrr_b(t_node **a_head, t_node **b_head, char **inst, char **p);

#endif