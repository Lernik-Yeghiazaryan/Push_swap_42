/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:17:30 by leyeghia          #+#    #+#             */
/*   Updated: 2022/06/30 16:54:09 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}					t_stack;

void	create_stack_front(t_stack **a, int n);
void	create_stack_back(t_stack **a, int n);

void	swap_stack(t_stack **s);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

void	push(t_stack **stack1, t_stack **stack2);
void	pa(t_stack **stack1, t_stack **stack2);
void	pb(t_stack **stack2, t_stack **stack1);

void	rotate(t_stack **s);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	revrotate(t_stack **s);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

int		ft_strlen(char *s);
int		ft_atoi(const char *s);
char	**ft_split(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strcmp(const char *str1, const char *str2);
void	ft_lstclear(t_stack **lst);

int		*divider(char *av);
int		count_words(char *str);
void	free_line(char **line);

int		is_sorted(int *arr, int length);
int		check_sort(t_stack *s);
void	sorting_2345(t_stack **a, t_stack **b, int count);
void	sorting_for_big_numbers(t_stack **a, t_stack **b, int length);
void	addressing(t_stack **a, int length);
void	print(t_stack **a, t_stack **b);

#endif
