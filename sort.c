/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:25:08 by dancel            #+#    #+#             */
/*   Updated: 2024/12/07 18:01:13 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_total *mega)
{
	int	n;

	n = mega->size_a;
	if (n == 2)
		return (swap('a', mega));
	if (n == 3)
		return (sort_3(mega));
	while (mega->size_b < n / 2)
		halve(n, mega);
	while (mega->size_a > 3)
		push('b', mega);
	if (mega->size_a == 2 && !is_sorted('a', mega))
		swap('a', mega);
	if (mega->size_a == 3 && !is_sorted('a', mega))
		sort_3(mega);
	find_cheaper(mega);
	put_min_above(mega);
}

void	sort_3(t_total *mega)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = mega->t_a->value;
	v2 = mega->t_a->next->value;
	v3 = mega->t_a->next->next->value;
	if (v3 > v1 && v3 < v2)
		return (swap('a', mega), rotate('a', mega));
	if (v1 > v2 && v1 < v3)
		swap('a', mega);
	if (v1 < v2 && v1 > v3)
		rrotate('a', mega);
	if (v3 < v1 && v3 > v2)
		rotate('a', mega);
	if (v2 > v3 && v2 < v1)
		return (swap('a', mega), rrotate('a', mega));
}

void	halve(int n, t_total *mega)
{
	int		cost;
	int		x;
	t_stack	*s;

	cost = INT_MAX;
	s = mega->t_a;
	while (s)
	{
		if (s->value <= n / 2 - 1
			&& (cost > s->index + 1 || cost > mega->size_a - s->index + 1))
		{
			if (s->index + 1 <= mega->size_a - s->index + 1)
			{
				cost = s->index + 1;
				x = s->index;
			}
			if (s->index + 1 > mega->size_a - s->index + 1)
			{
				cost = mega->size_a - s->index + 1;
				x = -s->index;
			}
		}
		s = s->next;
	}
	put_in_b(x, mega);
}

void	put_in_b(int x, t_total *mega)
{
	int	i;

	i = -1;
	if (x > 0)
	{
		while (++i < x)
			rotate('a', mega);
	}
	if (x < 0)
	{
		x = -x;
		while (++i < mega->size_a - x)
			rrotate('a', mega);
	}
	push('b', mega);
}

void	put_min_above(t_total *mega)
{
	t_stack	*s;
	int		i;
	int		n;

	i = -1;
	s = mega->t_a;
	while (s)
	{
		n = mega->size_a - s->index;
		if (s->value == 0 && s->index <= mega->size_a - s->index)
		{
			while (++i < s->index)
				rotate('a', mega);
		}
		if (s->value == 0 && s->index > mega->size_a - s->index)
		{
			while (++i < n)
				rrotate('a', mega);
		}
		s = s->next;
	}
}
