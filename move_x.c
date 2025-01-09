/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:23:17 by dancel            #+#    #+#             */
/*   Updated: 2024/12/07 16:10:46 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_x(int x, int y, char *comb, t_total *mega)
{
	int	i;
	int	a;
	int	b;

	a = mega->size_a;
	b = mega->size_b;
	i = -1;
	if (comb[1] == 'g' && (comb[2] == 'b' || comb[2] == 'a'))
	{
		while (++i < cmp(x, y, 0))
			rotate('r', mega);
		i = -1;
		while (comb[2] == 'b' && ++i < cmp(x - y, y - x, 1))
			rotate('b', mega);
		while (comb[2] == 'a' && ++i < cmp(x - y, y - x, 1))
			rotate('a', mega);
	}
	if (comb[0] == 'g' && comb[1] == 'd')
	{
		while (--x >= 0)
			rotate('b', mega);
		while (mega->size_a >= ++y)
			rrotate('a', mega);
	}
	move_x_next(x, y, comb, mega);
}

void	move_x_next(int x, int y, char *comb, t_total *mega)
{
	int	i;
	int	a;
	int	b;

	a = mega->size_a;
	b = mega->size_b;
	i = -1;
	if (comb[0] == 'd' && comb[1] == 'g')
	{
		while (mega->size_b >= ++x)
			rrotate('b', mega);
		while (--y >= 0)
			rotate('a', mega);
	}
	if (comb[1] == 'd' && (comb[2] == 'b' || comb[2] == 'a'))
	{
		while (++i < cmp(b - x, a - y, 0))
			rrotate('r', mega);
		i = -1;
		while (comb[2] == 'b' && ++i < cmp(b - x - a + y, a - y - b + x, 1))
			rrotate('b', mega);
		while (comb[2] == 'a' && ++i < cmp(b - x - a + y, a - y - b + x, 1))
			rrotate('a', mega);
	}
	push('a', mega);
}
