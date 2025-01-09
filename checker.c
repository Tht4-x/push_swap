/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:32:07 by dancel            #+#    #+#             */
/*   Updated: 2024/12/10 13:34:36 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	execute_instructions(char *s, t_total *mega)
{
	if (!s)
		exit_push_swap(mega, 1);
	if (ft_strncmp(s, "sa\n", 10) == 0 || ft_strncmp(s, "sb\n", 10) == 0)
		swap(s[1], mega);
	else if (ft_strncmp(s, "pa\n", 10) == 0 || ft_strncmp(s, "pb\n", 10) == 0)
		push(s[1], mega);
	else if (ft_strncmp(s, "ra\n", 10) == 0 || ft_strncmp(s, "rb\n", 10) == 0
		|| ft_strncmp(s, "rr\n", 10) == 0)
		rotate(s[1], mega);
	else if (ft_strncmp(s, "rra\n", 10) == 0 || ft_strncmp(s, "rrb\n", 10) == 0
		|| ft_strncmp(s, "rrr\n", 10) == 0)
		rrotate(s[2], mega);
	else
	{
		free(s);
		exit_push_swap(mega, 1);
	}
}

void	read_instructions(t_total *mega)
{
	char	*buffer;

	buffer = get_next_line(0);
	while (buffer)
	{
		execute_instructions(buffer, mega);
		free(buffer);
		buffer = get_next_line(0);
	}
	if (is_sorted('t', mega))
		ft_printf("OK\n", mega->result);
	else
		ft_printf("KO\n", mega->result);
}

int	main(int argc, char **argv)
{
	char	**args;
	t_total	*mega;
	int		i;

	if (argc < 2)
		return (1);
	args = only_one_tab(argv, 1);
	if (!args)
		return (ft_printf("Error\n"), 1);
	if (!valid_list(args, -1, 0))
	{
		i = -1;
		while (args[++i])
			free(args[i]);
		return (free(args), ft_printf("Error\n"), 1);
	}
	mega = search_min_in_args(args);
	if (!mega || !mega->t_a || !mega->result)
		exit_push_swap(mega, 1);
	read_instructions(mega);
	exit_push_swap(mega, 0);
	return (0);
}
