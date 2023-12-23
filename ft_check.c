/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:40:27 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/23 13:40:06 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_find_best_rank(t_Node **a, int rank_b)
{
	t_Node	*current_a;
	int		best_rank;

	current_a = *a;
	best_rank = find_max_rank_a(*a);
	while (current_a)
	{
		if ((current_a->rank > rank_b) && (best_rank > current_a->rank))
			best_rank = current_a->rank;
		current_a = current_a->next;
	}
	return (best_rank);
}

void	ft_final_sort(t_Node **a, t_Node **b)
{
	int		best_rank;

	if (!(*b) || !b)
		return ;
	// if ((*b)->next && ft_find_best_rank(a, (*b)->next->rank) == (*a)->rank)
	// {
	// 	sb(b, 1);
	// 	pa(a, b);
	// }
	while (ft_lstlast(*b)->rank > (*b)->rank
		&& ft_lstlast(*b)->rank < (*a)->rank)
		rrb(b, 1);
	//if (*b)
		best_rank = ft_find_best_rank(a, (*b)->rank);
	while ((*a)->rank != best_rank && *b)
	{
		if (find_r_or_rr(a, best_rank))
			ra(a, 1);
		else
			rra(a, 1);
	}
}

void	ft_check(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (argc > j)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			if (0 == ft_isdigit(argv[j][i])
				&& (argv[j][i] != ' ' && argv[j][i] != '-'))
			{
				ft_printf("found \"%c\" Error\n", argv[j][i]);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		j++;
	}
}

int	ft_check_same(t_Node **a, int size)
{
	t_Node	*tmp;
	t_Node	*cmp;

	cmp = (*a);
	size = 0;
	while (cmp)
	{
		tmp = cmp->next;
		while (tmp)
		{
			if (tmp->nbr == cmp->nbr)
			{
				ft_printf("Error : found 2 times %d", cmp->nbr);
				exit (EXIT_FAILURE);
			}
			tmp = tmp->next;
		}
		size++;
		cmp = cmp->next;
	}
	return (size);
}

bool	find_r_or_rr(t_Node **a, int best_rank)
{
	int		cost;
	t_Node	*tmp;

	cost = 0;
	tmp = *a;
	while (tmp->rank != best_rank && tmp && tmp->next)
	{
		cost++;
		tmp = tmp->next;
	}
	if (cost > count_size_a(*a) / 2)
		return (false);
	return (true);
}
