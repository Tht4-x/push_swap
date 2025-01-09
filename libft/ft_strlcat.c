/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:20:53 by dancel            #+#    #+#             */
/*   Updated: 2024/10/23 20:38:16 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			ldest;
	size_t			lsrc;
	unsigned int	i;

	i = 0;
	ldest = 0;
	lsrc = 0;
	while (dest[ldest] && ldest < size)
		ldest++;
	while (src[lsrc])
		lsrc++;
	if (size == 0)
		return (lsrc);
	if (ldest >= size)
		return (size + lsrc);
	while (src[i] && (ldest + i) < (size - 1))
	{
		dest[ldest + i] = src[i];
		i++;
	}
	dest[ldest + i] = '\0';
	return (ldest + lsrc);
}
