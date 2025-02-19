/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_switch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:26:50 by syukna            #+#    #+#             */
/*   Updated: 2025/02/08 15:50:02 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	switch_stack(t_stacknode **lst, char letter)
{
	int rank;

	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	rank = (*lst)->next->content;
	(*lst)->next->content = (*lst)->content;
	(*lst)->content = rank;
	if (letter == 'a')
		ft_printf("sa\n");
	else if	(letter == 'b')
		ft_printf("sb\n");
}

void	switch_both_stacks(t_stacknode **lsa, t_stacknode **lsb)
{
	switch_stack(lsa, 's');
	switch_stack(lsb, 's');
	ft_printf("ss\n");
}