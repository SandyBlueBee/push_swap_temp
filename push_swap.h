/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:09:01 by syukna            #+#    #+#             */
/*   Updated: 2025/02/19 12:28:02 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/* *******************************LIBRARIES********************************** */
/* ************************************************************************** */

# include "libft/libft.h"

/* ************************************************************************** */
/* *************************CONST GLOBAL VARIABLE**************************** */
/* ************************************************************************** */

#define ERROR_MSG "Error\n"

/* ************************************************************************** */
/* *******************************STRUCTURES********************************* */
/* ************************************************************************** */

typedef struct s_stacknode
{
	int					content;
	int					tpts;
	int					dpts;
	int					score;
	struct s_stacknode	*next;
	struct s_stacknode	*previous;
}	t_stacknode;

/* ************************************************************************** */
/* *******************************FUNCTIONS********************************** */
/* ************************************************************************** */

// error.c
int str_is_digit(char *str);
int ft_is_int(long int num);
int	is_duplicate(int *array, int argc);

// double_linked_list.c
t_stacknode	*ft_dblstnew(int content);
void	ft_dblstadd_front(t_stacknode **lst, t_stacknode *new);
void	ft_dblstadd_back(t_stacknode **lst, t_stacknode *new);
void	ft_dblstremove(t_stacknode **lst);

// push_swap.c
int		*convert_to_rank(int *a, int *b, int argc);
int		*setup_list(int *a, int **b, int argc, char **argv);
t_stacknode	*setup_dblk_list(int *a, int argc);

// switch.c
void	switch_stack(t_stacknode **lst, char letter);

// rotate.c
void	rotate_stack(t_stacknode **lst, char letter);
void	rotate_both_stacks(t_stacknode **lsa, t_stacknode **lsb);
void	rotate_rev_stack(t_stacknode **lst, char letter);
void	rotate_rev_both_stacks(t_stacknode **lsa, t_stacknode **lsb);

// send_back.c
void	send_back_down(t_stacknode **lst, char letter);
void	send_back_up(t_stacknode **lst, char letter);
void	send_back(t_stacknode **lsa, t_stacknode **lsb, int	rank);

// send_forward.c
void	send_forward(t_stacknode **lsa, t_stacknode **lsb);

// check.c
int		is_sorted(t_stacknode *lst);
int	count_dblklist(t_stacknode *lst);

// sort.c
void	sort_three(t_stacknode **lst, char letter);
void	ps_sort(t_stacknode **lst);

// score.c
void	ps_add_powers(t_stacknode **lst, int max);

// push.c
void	ps_push_stack(t_stacknode **lsone, t_stacknode **lstwo, char letter);
void	send_back_up(t_stacknode **lst, char letter);
void	send_back_down(t_stacknode **lst, char letter);

#endif