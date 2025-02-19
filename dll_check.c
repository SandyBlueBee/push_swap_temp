/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:50:36 by syukna            #+#    #+#             */
/*   Updated: 2025/02/11 16:00:46 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stacknode *lst)
{
	t_stacknode *head;

	if (!(lst) || !lst->next)
		return (1);
	head = lst;
	while (lst->next != head)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst= lst->next;
	}
	return (1);
}

int	count_dblklist(t_stacknode *lst)
{
	t_stacknode *head;
	int	count;
	
	if (!(lst))
		return (0);
	head = lst;
	count = 1;
	while(lst->next != head)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
