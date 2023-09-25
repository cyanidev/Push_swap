/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:47:31 by afelicia          #+#    #+#             */
/*   Updated: 2023/09/07 18:12:31 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*shift down all elements of stack by 1, tha last becomes the first one*/
void	reverse_rotate_a(t_stack	**stack)
{
	t_stack	*current;
	t_stack	*tmp;

	tmp = *stack;
	current = *stack;
	while (current->next->next != NULL)
		current = current->next;
	*stack = current->next;
	(*stack)->next = tmp;
	current->next = NULL;
	ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_stack	**stack)
{
	t_stack	*current;
	t_stack	*tmp;

	tmp = *stack;
	current = *stack;
	while (current->next->next != NULL)
		current = current->next;
	*stack = current->next;
	(*stack)->next = tmp;
	current->next = NULL;
	ft_putstr_fd("rrb\n", 1);
}
