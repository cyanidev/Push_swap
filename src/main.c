/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:16:23 by afelicia          #+#    #+#             */
/*   Updated: 2023/09/22 02:05:59 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init(int val, int index)
{
	t_stack	*newstack;

	newstack = (t_stack *)malloc(sizeof (t_stack));
	if (newstack == NULL)
		return (NULL);
	newstack->index = index;
	newstack->val = val;
	newstack->next = NULL;
	return (newstack);
}

t_stack	*put_stack_values(int argc, char **argv)
{
	t_stack	*head;
	t_stack	*tail;
	int		n;
	int		i;

	head = NULL;
	n = 0;
	i = 1;
	while (i < argc)
	{
		n = ft_newatoi(argv[i]);
		if (head == NULL)
			head = init(n, i);
		else
		{
			tail = head;
			while (tail->next != NULL)
				tail = tail->next;
			tail->next = init(n, i);
		}
		i++;
	}
	return (head);
}

void leaks(void) { system("leaks -q push_swap"); }

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stacklen;
	t_stack	*dup;
	
	dup = NULL;
	if (argc < 2)
		return (0);
	if (!(isok(argv) && finddups(argv)))
		ret_error("Error\n");
	stack_b = NULL;
	stack_a = put_stack_values(argc, argv);
	if (issorted(stack_a))
	{
		free_stack(&stack_a);
		ret_error("Already sorted\n");
	}
	stacklen = ft_stacklen(stack_a);
	if (stacklen > 11 && stacklen < 501)
		dup = put_stack_values(argc, argv);
	stack_a = sorted(stack_a, stack_b, stacklen, dup);
	if (stack_a != NULL || stack_b != NULL || stacklen == 0)
		free_stack(&stack_a);
	return (0);
}
