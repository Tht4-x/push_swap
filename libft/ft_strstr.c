/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:06:38 by dancel            #+#    #+#             */
/*   Updated: 2024/12/07 15:26:08 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char		*b;
	char		*l;
	size_t		i;
	size_t		j;

	b = (char *)big;
	l = (char *)little;
	i = 0;
	if (l[0] == '\0')
		return (b);
	while (b[i])
	{
		j = 0;
		while (b[i + j] == l[j])
		{
			j++;
			if (j == ft_strlen(l))
				return (&b[i]);
		}
		i++;
	}
	return (NULL);
}
