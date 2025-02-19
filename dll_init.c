/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:05:29 by syukna            #+#    #+#             */
/*   Updated: 2025/02/18 14:41:20 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacknode	*ft_dblstnew(int content)
{
	t_stacknode	*dblstnew;
	
	dblstnew = malloc(sizeof(t_stacknode));
	if (!dblstnew)
		return (NULL);
	dblstnew->tpts = -1;
	dblstnew->dpts = -1;
	dblstnew->content = content;
	dblstnew->next = dblstnew;
	dblstnew->previous = dblstnew;
	return (dblstnew);
}

void	ft_dblstadd_front(t_stacknode **lst, t_stacknode *new) 
{
	t_stacknode	*temp;
	
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		new->next = new;
		new->previous = new;
		*lst = new;
		return ;
	}
	temp = (*lst)->previous;
	new->next = *lst;
	new->previous = temp;
	(*lst)->previous = new;
	temp->next = new;
	*lst = new;
}

void	ft_dblstadd_back(t_stacknode **lst, t_stacknode *new)
{
	t_stacknode	*temp;
	t_stacknode	*first;
	
	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	first = *lst;
	while (temp->next != first)
		temp = temp->next;
	temp->next = new;
	new->tpts = -1;
	new->dpts = -1;
	new->score = -1;
	new->previous = temp;
	new->next = first;
	first->previous = new;
	return ;
}

void	ft_dblstremove(t_stacknode **lst) 
{
	t_stacknode	*current;
	t_stacknode	*prev;
	t_stacknode	*next;
	
	if (!lst || !*lst)
		return ;
	current = (*lst);
	if (current->next == current)
	{
		free(current);
		*lst = NULL;
		return ;
	}
	prev = current->previous;
	next = current->next;
	prev->next = next;
	next->previous = prev;
	*lst = next;
    free(current);
}
