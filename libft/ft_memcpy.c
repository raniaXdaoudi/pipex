/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radaoudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:27:05 by radaoudi          #+#    #+#             */
/*   Updated: 2021/12/03 11:15:22 by radaoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_cpy;
	const char	*src_cpy;

	i = 0;
	if (!dest && !src)
		return (0);
	dest_cpy = dest;
	src_cpy = src;
	while (i < n)
	{
		*dest_cpy = *src_cpy;
		dest_cpy++;
		src_cpy++;
		i++;
	}
	return (dest);
}
