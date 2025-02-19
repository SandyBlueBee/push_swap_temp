/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:02:22 by syukna            #+#    #+#             */
/*   Updated: 2025/02/11 16:19:57 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stacknode **lst, char letter)
{
	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	t_stacknode *old_head;
	t_stacknode *new_head;
	
	old_head = *lst;
	new_head = (*lst)->next;

	*lst = new_head;
	if (letter == 'a')
		ft_printf("ra\n");
	else if	(letter == 'b')
		ft_printf("rb\n");
}

void	rotate_both_stacks(t_stacknode **lsa, t_stacknode **lsb)
{
	if ((!lsa || !(*lsa) || !(*lsa)->next) && (!lsb || !(*lsb) || !(*lsb)->next))
		return;
	rotate_stack(lsa, 's');
	rotate_stack(lsb, 's');
	ft_printf("rr\n");
}

void	rotate_rev_stack(t_stacknode **lst, char letter)
{
	if (!lst || !(*lst) || !(*lst)->previous)
		return ;
	t_stacknode *old_head;
	t_stacknode *new_head;
	
	old_head = *lst;
	new_head = (*lst)->previous;

	*lst = new_head;
	if (letter == 'a')
		ft_printf("rra\n");
	else if	(letter == 'b')
		ft_printf("rrb\n");
}

void	rotate_rev_both_stacks(t_stacknode **lsa, t_stacknode **lsb)
{
	if ((!lsa || !(*lsa) || !(*lsa)->previous) && (!lsb || !(*lsb) || !(*lsb)->previous))
		return;
	rotate_rev_stack(lsa, 's');
	rotate_rev_stack(lsb, 's');
	ft_printf("rrr\n");
}