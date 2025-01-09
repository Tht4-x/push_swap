/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_set_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:21:07 by dancel            #+#    #+#             */
/*   Updated: 2024/12/07 17:20:22 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ps_strjoin(t_total *mega, char *add_to_result)
{
	char	*new_result;

	new_result = ft_strjoin(mega->result, add_to_result);
	if (!new_result)
		exit_push_swap(mega, 1);
	if (mega->result)
		free(mega->result);
	return (new_result);
}

void	swap(char c, t_total *mega)
{
	int	temp;

	if ((c == 'a' || c == 's') && mega->size_a >= 2)
	{
		temp = mega->t_a->value;
		mega->t_a->value = mega->t_a->next->value;
		mega->t_a->next->value = temp;
		if (c == 'a' || (c == 's' && mega->size_b < 2))
			mega->result = ps_strjoin(mega, "sa\n");
	}
	if ((c == 'b' || c == 's') && mega->size_b >= 2)
	{
		temp = mega->t_b->value;
		mega->t_b->value = mega->t_b->next->value;
		mega->t_b->next->value = temp;
		if (c == 'b' || (c == 's' && mega->size_a < 2))
			mega->result = ps_strjoin(mega, "sb\n");
	}
	if (c == 's' && mega->size_a >= 2 && mega->size_b >= 2)
		mega->result = ps_strjoin(mega, "ss\n");
}

void	push(char c, t_total *mega)
{
	if (c == 'a' && mega->size_b > 0)
	{
		push_next(mega, 'a', mega->t_b, mega->t_a);
		mega->size_a++;
		mega->size_b--;
		if (mega->size_b == 0)
			mega->t_b = NULL;
		mega->result = ps_strjoin(mega, "pa\n");
	}
	if (c == 'b' && mega->size_a > 0)
	{
		push_next(mega, 'b', mega->t_a, mega->t_b);
		mega->size_b++;
		mega->size_a--;
		if (mega->size_a == 0)
			mega->t_a = NULL;
		mega->result = ps_strjoin(mega, "pb\n");
	}
}

void	push_next(t_total *mega, char c, t_stack *s_x, t_stack *s_y)
{
	t_stack	*current;
	t_stack	*previous;

	previous = NULL;
	current = create_new_element(mega, c, s_x, s_y);
	while (current->next)
	{
		current = current->next;
		current->index++;
	}
	current = s_x;
	while (current->next)
	{
		current->value = current->next->value;
		previous = current;
		current = current->next;
	}
	if (!previous && c == 'a')
		mega->t_b = NULL;
	else if (!previous && c == 'b')
		mega->t_a = NULL;
	else
		previous->next = NULL;
	free(current);
}

t_stack	*create_new_element(t_total *mega, char c, t_stack *s_x, t_stack *s_y)
{
	t_stack	*current;

	current = malloc(sizeof(t_stack));
	if (!current)
		exit_push_swap(mega, 1);
	if (c == 'a')
		mega->t_a = current;
	if (c == 'b')
		mega->t_b = current;
	current->index = 0;
	current->value = s_x->value;
	current->next = s_y;
	s_y = current;
	return (current);
}
