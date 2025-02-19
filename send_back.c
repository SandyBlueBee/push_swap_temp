/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:05:45 by syukna            #+#    #+#             */
/*   Updated: 2025/02/18 15:54:24 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_back_down(t_stacknode **lst, char letter)
{
	rotate_stack(lst, letter);
	ps_add_powers(lst, 5);
}
void	send_back_up(t_stacknode **lst, char letter)
{
	rotate_rev_stack(lst, letter);
	ps_add_powers(lst, 5);
}

void	send_back(t_stacknode **lsa, t_stacknode **lsb, int	rank)
{
	t_stacknode	*temp;
	t_stacknode	*first;
	int	go;

	while (rank >= 0)
	{
		if (!*lsb)
			return;
		temp = *lsb;
		first = *lsb;
		int	to_find;

		to_find = 1;
		go = 1;
		while ((temp != first || go) && to_find && *lsb)
		{
			ps_add_powers(lsb, 5);
			if (temp->content == rank)
			{
				to_find = 0;
				if (temp->tpts <= temp->dpts)
					while (temp->tpts > 1)
						send_back_down(lsb, 'b');
				else
				{
					while (temp->dpts > 2)
						send_back_up(lsb, 'b');
					rotate_rev_stack(lsb,'b');
				}
				ps_push_stack(lsb, lsa, 'a');
				temp = *lsb;
			}
			temp = temp->next;
			go = 0;
		}
		temp = temp->next;
		rank--;
	}
}