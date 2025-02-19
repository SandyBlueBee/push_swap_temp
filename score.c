/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:26:52 by syukna            #+#    #+#             */
/*   Updated: 2025/02/19 12:27:38 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_score(t_stacknode *node, int max)
{
	if (node->content > max)
		node->score = 100;
	else if (node->tpts <= node->dpts)
	{
		node->score = node->tpts;
		node->dpts = 100;
	}
	else if (node->dpts <= node->tpts)
	{
		node->score = node->dpts;
		node->tpts = 100;
	}
}

void	set_score_list(t_stacknode **lst, int max)
{
	t_stacknode	*temp;
	t_stacknode	*first;
	int	go;

	go = 1;
	temp = *lst;
	first = temp;
	while ((temp != first || go))
	{
		set_score(temp, max);
		temp = temp->next;
		go = 0;
	}
}

int	set_max(t_stacknode **lst, int max)
{
	int	i;
	int	current_min;
	int	go;
	t_stacknode	*temp;
	t_stacknode	*first;
	
	i = 100;
	current_min = -1;
	while (max)
	{
		go = 1;
		temp = *lst;
		first = temp;
		while (temp != first || go)
		{
			if (temp->content < i && temp->content > current_min)
				i = temp->content; 
			go = 0;
			temp = temp->next;
		}
		current_min = i;
		max--;
	}
	return (current_min);	
}

void	ps_add_powers(t_stacknode **lst, int max)
{
	t_stacknode	*prev;
	int			count;

	count = 1;
	(*lst)->tpts = count;
	prev = (*lst);
	while ((*lst)->next != prev)
	{
		(*lst) = (*lst)->next;
		count++;
		(*lst)->tpts = count;
	}
	(*lst) = prev;
	count = 2;
	while ((*lst)->previous != prev)
	{
		(*lst) = (*lst)->previous;
		(*lst)->dpts = count;
		count++;
	}
	(*lst) = (*lst)->previous;
	(*lst)->dpts = count;
	max = set_max(lst, max);
	set_score_list(lst, max);
}