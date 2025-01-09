/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_mega.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:03:50 by dancel            #+#    #+#             */
/*   Updated: 2024/12/10 13:06:32 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_total	*search_min_in_args(char **args)
{
	int	min;
	int	temp;
	int	*value;
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (args[++i])
		len++;
	i = -1;
	min = INT_MAX;
	value = malloc(len * sizeof(int));
	if (!value)
		return (NULL);
	while (++i < len)
	{
		if (atoi(args[i]) < min)
		{
			min = atoi(args[i]);
			temp = atoi(args[i]);
		}
		value[i] = 0;
	}
	return (replace_value_by_pos(args, value, temp, len));
}

t_total	*replace_value_by_pos(char **args, int *value, int temp, int len)
{
	int	i;
	int	j;
	int	min;

	j = 0;
	while (++j < len)
	{
		i = -1;
		min = INT_MAX;
		while (++i < len)
		{
			if (atoi(args[i]) < min && atoi(args[i]) > temp)
				min = atoi(args[i]);
		}
		i = -1;
		while (++i < len)
		{
			if (atoi(args[i]) == min)
			{
				temp = min;
				value[i] = j;
			}
		}
	}
	return (create_mega(args, value, len));
}

t_total	*create_mega(char **args, int *value, int len)
{
	int		i;
	t_stack	*s_a;
	t_total	*mega;

	i = -1;
	while (args[++i])
		free(args[i]);
	free(args);
	s_a = NULL;
	mega = malloc(sizeof(t_total));
	if (!mega)
		return (NULL);
	i = -1;
	while (++i < len)
		fill_stack_a(&s_a, value[i], i, mega);
	free(value);
	mega->t_a = s_a;
	mega->size_a = len;
	mega->t_b = NULL;
	mega->size_b = 0;
	mega->result = ft_strdup("");
	return (mega);
}

void	fill_stack_a(t_stack **s_a, int value, int i, t_total *mega)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		exit_push_swap(mega, 1);
	new_node->value = value;
	new_node->index = i;
	new_node->next = NULL;
	if (*s_a == NULL)
		*s_a = new_node;
	else
	{
		current = *s_a;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}
