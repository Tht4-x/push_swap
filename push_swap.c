/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:39:33 by dancel            #+#    #+#             */
/*   Updated: 2024/12/10 13:22:52 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!is_sorted('t', mega))
		sort(mega);
	ft_printf("%s", mega->result);
	exit_push_swap(mega, 0);
	return (0);
}
