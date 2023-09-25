/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:44:48 by afelicia          #+#    #+#             */
/*   Updated: 2023/09/21 13:00:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (stack_a == NULL)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = tmp;
	ft_putstr_fd("pb\n", 1);
}

void	pusha(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (stack_b == NULL)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = tmp;
	ft_putstr_fd("pa\n", 1);
}
