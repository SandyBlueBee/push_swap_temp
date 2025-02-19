/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:23:54 by syukna            #+#    #+#             */
/*   Updated: 2025/02/19 16:52:45 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *convert_to_rank(int *a, int *b, int argc)
{
	int i;
	int j;
	int count;
	
	i = 0;
	count = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (j < argc - 1)
		{
			if (b[i] > b[j])
				count++; 
			j++;
		}
		a[i] = count;
		count = 0;
		i++;
	}
	return (a);
}
/**
 * @brief Optimizes and prints the operations.
 * @param argv Program data.(All the data needed for the program)
 */
int	count_split(char **argv)
{
	int	count;

	count = 0;
	ft_printf("yello\n");
	while (argv[count])
		count++;
	ft_printf("yello %d\n", count);
	return (count - 1);
}
int	*setup_list(int *a, int **b, int argc, char **argv)
{
	int i;
	long int num;
	char	**rtnlist;
	
	i = 0;
	if (argc == 2)
	{
		rtnlist = ft_split(argv[1], ' ');
		ft_printf("%s\n", rtnlist[4]);
	}
	else
		rtnlist = &argv[1];
	while (i < count_split(rtnlist))
	{
		ft_printf("yello rtnlist[i] %d\n", rtnlist[i]);

		if (!str_is_digit(rtnlist[i]))
			return (ft_printf(ERROR_MSG), NULL);
		num = ft_atoi(rtnlist[i]); 
		if (!ft_is_int(num))
			return (ft_printf(ERROR_MSG), NULL);
		(*b)[i] = num;
		i++;
	}
	if (is_duplicate((*b), argc - 1))
    	return (ft_printf(ERROR_MSG), NULL);
	convert_to_rank(a, (*b), argc);
	free((*b));
	(*b) = calloc((argc - 1) , sizeof(int));
	return (a);
}

t_stacknode	*setup_dblk_list(int *a, int argc)
{
	t_stacknode	*dblist;
	t_stacknode	*new;
	int i;

	i = 0;
	dblist = ft_dblstnew(a[i]);
	i++;
	while (i < (argc - 1))
	{
		new = ft_dblstnew(a[i]);
		ft_dblstadd_back(&dblist, new);
		i++;
	}
	return (dblist);
}

t_stacknode	*setup(int argc, char **argv)
{
	int *a;
	int *b;
	t_stacknode	*dblist;

	if (argc < 2)
		return (NULL);
	a = calloc((argc - 1), sizeof(int));
	b = calloc((argc - 1), sizeof(int));
	a = setup_list(a, &b, argc, argv);
	if (!a)
		return (NULL);
	dblist = setup_dblk_list(a, argc);
	return (dblist);
}

//int main()
//{
//	int i = 0;
//	char **split = ft_split("", 'a');
//	while (split[i])
//	{
//		printf("%s", split[i]);
//		i++;
//	}
//	free(split);
//}

int main(int argc, char **argv)
{
	t_stacknode	*lsa;
	lsa = setup(argc, argv);
	// ft_printf("count_dblklist(lsa) before = %d\n", count_dblklist(lsa));
	ps_sort(&lsa);
	// ft_printf("is_sorted(lsa) = %d\n", is_sorted(lsa));
	// ft_printf("count_dblklist(lsa) after = %d\n", count_dblklist(lsa));
	return (0);
}

// switch_stack(&lsa,'a');
// rotate_stack(&lsa,'a');