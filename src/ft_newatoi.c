/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:22:56 by afelicia          #+#    #+#             */
/*   Updated: 2023/09/22 02:12:56 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_newatoi(char *str)
{
	int			i;
	long long	n;
	int			sign;

	i = 0;
	n = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (i == 0 && str[i] == '-') 
	{
		i++;
		if (str[i] == '-' || str[i++] != '\0')
			ret_error("Error");
		sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (str[i++] - '0') + (n * 10);
		if (str[i] == '-')
			ret_error("Error");
	}
	if (n > INT_MAX || n < INT_MIN)
		ret_error("Error\n");
	return (n * sign);
}
