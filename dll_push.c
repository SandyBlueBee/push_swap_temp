/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:27:50 by syukna            #+#    #+#             */
/*   Updated: 2025/02/17 15:58:34 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_push_stack(t_stacknode **lsone, t_stacknode **lstwo, char letter)
{
	int	rank;
	t_stacknode *new;
	
	if (!*lsone || !lsone)
		return ;
	rank = (*lsone)->content;
	ft_dblstremove(lsone);
	new = ft_dblstnew(rank);
	ft_dblstadd_front(lstwo, new);
	if (letter == 'a')
		ft_printf("pa\n");
	else if (letter == 'b')
		ft_printf("pb\n");
}