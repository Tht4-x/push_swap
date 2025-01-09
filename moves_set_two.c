/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_set_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:22:09 by dancel            #+#    #+#             */
/*   Updated: 2024/12/07 15:22:12 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(char c, t_total *mega)
{
	t_stack	*current;
	int		temp;

	if ((c == 'a' || c == 'r') && mega->size_a >= 2)
	{
		current = mega->t_a;
		temp = current->value;
		while (current->next)
		{
			current->value = current->next->value;
			current = current->next;
		}
		current->value = temp;
		if (c == 'a' || (c == 'r' && mega->size_b < 2))
			mega->result = ps_strjoin(mega, "ra\n");
	}
	rotate_next(c, mega);
}

void	rotate_next(char c, t_total *mega)
{
	t_stack	*current;
	int		temp;

	if ((c == 'b' || c == 'r') && mega->size_b >= 2)
	{
		current = mega->t_b;
		temp = current->value;
		while (current->next)
		{
			current->value = current->next->value;
			current = current->next;
		}
		current->value = temp;
		if (c == 'b' || (c == 'r' && mega->size_a < 2))
			mega->result = ps_strjoin(mega, "rb\n");
	}
	if (c == 'r' && mega->size_a >= 2 && mega->size_b >= 2)
		mega->result = ps_strjoin(mega, "rr\n");
}

void	rrotate(char c, t_total *mega)
{
	t_stack	*current;
	t_stack	*previous;

	if ((c == 'a' || c == 'r') && mega->size_a >= 2)
	{
		current = mega->t_a;
		while (current->next)
		{
			previous = current;
			current = current->next;
		}
		previous->next = NULL;
		current->index = 0;
		current->next = mega->t_a;
		mega->t_a = current;
		while (current->next)
		{
			current->next->index++;
			current = current->next;
		}
		if (c == 'a' || (c == 'r' && mega->size_b < 2))
			mega->result = ps_strjoin(mega, "rra\n");
	}
	rrotate_next(c, mega);
}

void	rrotate_next(char c, t_total *mega)
{
	t_stack	*current;
	t_stack	*previous;

	if ((c == 'b' || c == 'r') && mega->size_b >= 2)
	{
		current = mega->t_b;
		while (current->next)
		{
			previous = current;
			current = current->next;
		}
		previous->next = NULL;
		current->index = 0;
		current->next = mega->t_b;
		mega->t_b = current;
		while (current->next)
		{
			current->next->index++;
			current = current->next;
		}
		if (c == 'b' || (c == 'r' && mega->size_a < 2))
			mega->result = ps_strjoin(mega, "rrb\n");
	}
	if (c == 'r' && mega->size_a >= 2 && mega->size_b >= 2)
		mega->result = ps_strjoin(mega, "rrr\n");
}
