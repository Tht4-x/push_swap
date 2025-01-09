/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:22:35 by dancel            #+#    #+#             */
/*   Updated: 2024/12/12 14:02:39 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**only_one_tab(char **argv, int i)
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	**args;

	s1 = ft_strdup(argv[1]);
	if (!s1)
		return (NULL);
	while (argv[++i])
	{
		s2 = ft_strjoin(" ", argv[i]);
		if (!s2)
			return (free(s1), NULL);
		s3 = ft_strjoin(s1, s2);
		if (!s3)
			return (free(s1), free(s2), NULL);
		free(s1);
		free(s2);
		s1 = s3;
	}
	args = ft_split(s1, ' ');
	free(s1);
	if (!args)
		return (NULL);
	return (args);
}

char	**valid_list(char **args, int i, int j)
{
	while (args != NULL && args[++i])
	{
		if (!(args[i][0] == '+' || args[i][0] == '-'
			|| (args[i][0] >= '0' && args[i][0] <= '9')))
			return (NULL);
		if ((args[i][0] == '+' || args[i][0] == '-')
			&& (args[i][1] < '0' || args[i][1] > '9'))
			return (NULL);
		j = 0;
		while (args[i][++j])
		{
			if (args[i][j] < '0' || args[i][j] > '9')
				return (NULL);
		}
		if ((ft_atoll(args[i]) > 2147483647 || ft_atoll(args[i]) < -2147483648))
			return (NULL);
		j = i;
		while (args[++j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (NULL);
		}
	}
	return (args);
}

int	is_sorted(char c, t_total *mega)
{
	t_stack	*current;

	if (c == 'a' || c == 't')
	{
		current = mega->t_a;
		while (current && current->next)
		{
			if (current->value > current->next->value)
				return (0);
			current = current->next;
		}
		if (c == 't' && mega->size_b != 0)
			return (0);
	}
	if (c == 'b')
	{
		current = mega->t_b;
		while (current && current->next)
		{
			if (current->value < current->next->value)
				return (0);
			current = current->next;
		}
	}
	return (1);
}

void	exit_push_swap(t_total *mega, int error)
{
	if (mega)
	{
		if (mega->t_a)
			free_stack(mega->t_a);
		if (mega->t_b)
			free_stack(mega->t_b);
		if (mega->result)
			free(mega->result);
		free(mega);
	}
	if (error)
		write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack *t_x)
{
	t_stack	*temp;

	if (t_x->next)
	{
		while (t_x->next)
		{
			temp = t_x;
			t_x = t_x->next;
			free(temp);
		}
	}
	free(t_x);
}
