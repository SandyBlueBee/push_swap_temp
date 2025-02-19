/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:50:19 by syukna            #+#    #+#             */
/*   Updated: 2025/02/19 12:07:00 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_forward_down(t_stacknode **lst, char letter)
{
	rotate_stack(lst, letter);
	ps_add_powers(lst, 5);
}
void	send_forward_up(t_stacknode **lst, char letter)
{
	rotate_rev_stack(lst, letter);
	ps_add_powers(lst, 5);
}

void	send_forward(t_stacknode **lsa, t_stacknode **lsb)
{
	t_stacknode	*temp;
	t_stacknode	*first;
	t_stacknode	*chosen;
	int	go;
	int	min_score;
	int	max;
	
	while (count_dblklist(*lsa) > 3)
	{
		go = 1;
		temp = *lsa;
		first = temp;
		max = count_dblklist(*lsa)/ 3;
		ps_add_powers(lsa, max);
		min_score = 100;
		while ((temp != first || go) && *lsa)
		{
			go = 0;
			if (temp->score < min_score)
			{
				min_score = temp->score;
				chosen = temp;
			}
			// ft_printf("SEND FORWARD rank= %d tpts= %d dpts= %d score= %d\n", temp->content, temp->tpts, temp->dpts, temp->score);
			temp = temp->next;
		}
		// ft_printf("CHOSEN rank= %d tpts= %d dpts= %d score= %d\n", chosen->content, chosen->tpts, chosen->dpts, chosen->score);
		if (chosen->tpts <= chosen->dpts)
			while (chosen->tpts > 1)
				send_back_down(lsa, 'a');
		else
		{
			while (chosen->dpts > 2)
				send_back_up(lsa, 'a');
			rotate_rev_stack(lsa,'a');
		}
		ps_push_stack(lsa, lsb, 'b');
	}
}