/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andie <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:55:57 by andie             #+#    #+#             */
/*   Updated: 2023/09/21 12:56:00 by andie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*merge(t_stack *left, t_stack *right)
{
	t_stack	*result;

	result = NULL;
	if (left == NULL)
		return (right);
	else if (right == NULL)
		return (left);
	if (left->val <= right->val)
	{
		result = left;
		result->next = merge(left->next, right);
	}
	else
	{
		result = right;
		result->next = merge(left, right->next);
	}
	return (result);
}

void	split(t_stack *head, t_stack **left, t_stack **right)
{
	t_stack	*fast;
	t_stack	*slow;

	slow = head;
	fast = head->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*left = head;
	*right = slow->next;
	slow->next = NULL;
}

t_stack	*merge_sort(t_stack **sorted)
{
	t_stack	*head;
	t_stack	*left;
	t_stack	*right;

	head = *sorted;
	if (head == NULL || head->next == NULL)
		return (head);
	split(head, &left, &right);
	merge_sort(&left);
	merge_sort(&right);
	*sorted = merge(left, right);
	return (*sorted);
}
