/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:38:00 by afelicia          #+#    #+#             */
/*   Updated: 2023/09/07 18:15:40 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swaps the first 2 elements, does nothing if there's just one or less elements
void	swap_b(t_stack	*stack)
{
	int	tmp;

	tmp = stack->val;
	stack->val = stack->next->val;
	stack->next->val = tmp;
	ft_putstr_fd("sb\n", 1);
}

void	swap_a(t_stack	*stack)
{
	int	tmp;

	tmp = stack->val;
	stack->val = stack->next->val;
	stack->next->val = tmp;
	ft_putstr_fd("sa\n", 1);
}

/*every element goes up 1 spot, thi first one becomes the last one*/
void	rotate_b(t_stack	**stack)
{
	t_stack	*last;
	t_stack	*tmp;

	last = *stack;
	tmp = *stack;
	while (last && last->next != NULL)
		last = last->next;
	*stack = tmp->next;
	tmp->next = NULL;
	last->next = tmp;
	ft_putstr_fd("rb\n", 1);
}

void	rotate_a(t_stack	**stack)
{
	t_stack	*last;
	t_stack	*tmp;

	last = *stack;
	tmp = *stack;
	while (last && last->next != NULL)
		last = last->next;
	*stack = tmp->next;
	tmp->next = NULL;
	last->next = tmp;
	ft_putstr_fd("ra\n", 1);
}
