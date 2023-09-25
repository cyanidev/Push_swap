/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:15:03 by afelicia          #+#    #+#             */
/*   Updated: 2023/09/21 12:47:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				index;
	int				val;
	struct s_stack	*next;
}	t_stack;

int		ft_stacklen(t_stack *stack);
int		ft_strcmp(char *s1, char *s2);
int		isok(char **argv);
int		finddups(char **argv);
int		ret_error(char *str);
void	free_stack(t_stack **stack);
int		ft_newatoi(char *str);
int		issorted(t_stack	*stack);
t_stack	*sort_three(t_stack	*stack);
int		maxval(t_stack *stack);
t_stack	*maxvalue(t_stack *stack);
t_stack	*finding_key_nbr(t_stack *stack_a, int key_nbr, int stacklen);
int		searchkey(t_stack *srted, int pos);
t_stack	*minval(t_stack *stack);
t_stack	*sorted(t_stack	*stack_a, t_stack *stack_b, int len, t_stack *dup);
void	reverse_rotate_a(t_stack **stack);
void	reverse_rotate_b(t_stack **stack);
void	rotate_a(t_stack **stack);
void	rotate_b(t_stack **stack);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	pusha(t_stack **stack_a, t_stack **stack_b);
void	pushb(t_stack **stack_a, t_stack **stack_b);
t_stack	*merge_sort(t_stack	**sorted);
t_stack	*sort100(t_stack *stack_a, t_stack *stack_b, int len, t_stack *dup);
t_stack	*sort500(t_stack *stack_a, t_stack *stack_b, int len, t_stack *dup);

#endif
