/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:14:53 by syukna            #+#    #+#             */
/*   Updated: 2025/02/08 14:43:47 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int str_is_digit(char *str)
{
	int i;

	i = 0;

	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int ft_is_int(long int num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

int	is_duplicate(int *array, int size)
{
	int i;
	int j;
	
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}