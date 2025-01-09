/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:56:00 by dancel            #+#    #+#             */
/*   Updated: 2024/12/07 16:30:24 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_cheaper(t_total *mega)
{
	t_stack	*s;
	int		cost;
	int		x;
	int		y;
	char	*comb;

	while (mega->size_b != 0)
	{
		cost = INT_MAX;
		s = mega->t_b;
		while (s)
		{
			if (cost > find_cost(cost, s->index, find_y(s->value, mega), mega))
			{
				x = s->index;
				y = find_y(s->value, mega);
				cost = find_cost(cost, s->index, y, mega);
				comb = find_comb(cost, s->index, y, mega);
			}
			s = s->next;
		}
		move_x(x, y, comb, mega);
	}
}

int	find_y(int v, t_total *mega)
{
	t_stack	*s;

	s = mega->t_a;
	while (s->next)
	{
		if (v > s->value && v < s->next->value)
			return (s->next->index);
		if (s->value > s->next->value && (v > s->value || v < s->next->value))
			return (s->next->index);
		s = s->next;
	}
	return (0);
}

int	find_cost(int cost, int x, int y, t_total *mega)
{
	int	a;
	int	b;

	a = mega->size_a;
	b = mega->size_b;
	if (cost > cmp(x, y, 0) + cmp(x - y, y - x, 1) + 1)
		cost = cmp(x, y, 0) + cmp(x - y, y - x, 1) + 1;
	if (cost > x + a - y + 1)
		cost = x + a - y + 1;
	if (cost > b - x + y + 1)
		cost = b - x + y + 1;
	if (cost > cmp(b - x, a - y, 0) + cmp(b - x - a + y, a - y - b + x, 1) + 1)
		cost = cmp(b - x, a - y, 0) + cmp(b - x - a + y, a - y - b + x, 1) + 1;
	return (cost);
}

char	*find_comb(int cost, int x, int y, t_total *mega)
{
	char	*comb;
	int		a;
	int		b;

	a = mega->size_a;
	b = mega->size_b;
	if (cost == cmp(x, y, 0) + cmp(x - y, y - x, 1) + 1)
	{
		if (x - y >= y - x)
			comb = "ggb";
		else
			comb = "gga";
	}
	else if (cost == x + a - y + 1)
		comb = "gd-";
	else if (cost == b - x + y + 1)
		comb = "dg-";
	else
	{
		if (b - x - a + y >= a - y - b + x)
			comb = "ddb";
		else
			comb = "dda";
	}
	return (comb);
}

int	cmp(int a, int b, int mode)
{
	if (mode == 0 && a <= b)
		return (a);
	if (mode == 0 && b < a)
		return (b);
	if (mode == 1 && a >= b)
		return (a);
	if (mode == 1 && b > a)
		return (b);
	return (0);
}

// void	move_x(int x, int y, char *comb, t_total *mega)
// {
// 	if (comb[0] == 'h')
// 	{
// 		while (--x >= 0)
// 			rotate('b', mega);
// 	}
// 	if (comb[0] == 'b')
// 	{
// 		while (mega->size_b >= ++x)
// 			rrotate('b', mega);
// 	}
// 	if (comb[1] == 'h')
// 	{
// 		while (--y >= 0)
// 			rotate('a', mega);
// 	}
// 	if (comb[1] == 'b')
// 	{
// 		while (mega->size_a >= ++y)
// 			rrotate('a', mega);
// 	}
// 	push('a', mega);
// }