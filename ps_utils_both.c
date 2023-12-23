/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_both.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:21:38 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/23 13:52:27 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void    rrr(t_Node **a, t_Node **b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_printf("rrr\n");
}

void    ss(t_Node **a, t_Node **b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}

void    rr(t_Node **a, t_Node **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}

int	find_min(t_Node *a)
{
	int	min;

	min = 500;
	while (a)
	{
		if (min > a->rank)
			min = a->rank;
		a = a->next;
	}
	return (min);
}

int	ft_find_next_rank(t_Node *a, int to_find)
{
	int i;
	int j;
	int last_rank;

	j = -1;
	i = 0;
	last_rank = 0;
	while (a->rank && ++j)
	{
		if (a->rank < to_find && last_rank == 0)
			i = j;
		if (a->rank < to_find)
			last_rank = j;
		a = a->next;
	}
	if (i > last_rank - j)
	{
		if (i > j / 2)
			return (i * -1);
		else
			return (i);
	}
	if (i < last_rank - j)
			return ((j - last_rank) * -1);
	return (i);
}
