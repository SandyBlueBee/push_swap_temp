/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:00:36 by syukna            #+#    #+#             */
/*   Updated: 2025/02/19 12:27:06 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stacknode **lst, char letter)
{
	int prev;
	int next;

	if (is_sorted(*lst))
		return ;
	prev = (*lst)->previous->content;
	next = (*lst)->next->content;
	if ((*lst)->content > next && (*lst)->content < prev && prev > next)
		switch_stack(lst, letter);
	else if ((*lst)->content < next && (*lst)->content < prev && prev < next)
	{
		rotate_rev_stack(lst, letter);
		switch_stack(lst, letter);
	}
	else if ((*lst)->content < next && (*lst)->content > prev && prev < next)
		rotate_rev_stack(lst, letter);
	else if ((*lst)->content > next && (*lst)->content > prev && prev > next)
		rotate_stack(lst, letter);
	else if ((*lst)->content > next && (*lst)->content > prev && prev < next)
	{
		switch_stack(lst, letter);
		rotate_rev_stack(lst, letter);
	}
}

// case 1: 1 0 2
// case 2: 0 2 1
// case 3: 1 2 0
// case 4: 2 0 1
// case 5: 2 1 0


void	show_stacks(t_stacknode **lsa, t_stacknode **lsb)
{
	t_stacknode	*first_a;
	t_stacknode	*first_b;
	t_stacknode *temp;
	if (*lsa)
	{
		first_a = *lsa;
	temp = *lsa;
	ft_printf("\n--\nLSA\n--\n\n");
	while (temp->next != first_a)
	{
		ft_printf("rank= %d tpts= %d dpts= %d score= %d\n", temp->content, temp->tpts, temp->dpts, temp->score);
		temp = temp->next;
	}
	ft_printf("rank= %d tpts= %d dpts= %d score= %d\n", temp->content, temp->tpts, temp->dpts, temp->score);
	}
	else
		ft_printf("\n--\nLSA empty\n--\n\n");
	if (*lsb)
	{
		temp = *lsb;
		first_b = *lsb;
		ft_printf("\n\n--\nLSB\n--\n\n");
		while (temp->next != first_b)
		{
			ft_printf("rank= %d tpts= %d dpts= %d score= %d\n", temp->content, temp->tpts, temp->dpts, temp->score);
			temp = temp->next;
		}
		ft_printf("rank= %d tpts= %d dpts= %d score= %d\n\n", temp->content, temp->tpts, temp->dpts, temp->score);
	}
	else
		ft_printf("\n--\nLSB empty\n--\n\n");
}


void	ps_sort(t_stacknode **lsa)
{
	t_stacknode	*lsb;
	int	total;
	// t_stacknode	*chosen;
	int	value;

	value = -1;
	
	lsb = ft_dblstnew(value);

	total = count_dblklist(*lsa);
	// show_stacks(lsa, &lsb);
	send_forward(lsa, &lsb);
	sort_three(lsa, 'a');
	// show_stacks(lsa, &lsb);
	send_back(lsa, &lsb, total - 1);
	// show_stacks(lsa, &lsb);
}