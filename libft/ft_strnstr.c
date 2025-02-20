/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radaoudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:56:29 by radaoudi          #+#    #+#             */
/*   Updated: 2021/11/29 15:28:29 by radaoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;
	char	*s1_bis;

	i = 0;
	s1_bis = (char *)s1;
	n_len = ft_strlen(s2);
	if (s1 == s2 || n_len == 0)
		return (s1_bis);
	while (s1_bis[i] != '\0' && i < len)
	{
		if (s1_bis[i] == s2[0])
		{
			j = 0;
			while (s1_bis[i + j] != '\0' && s2[j] != '\0'
				&& s1_bis[i + j] == s2[j] && i + j < len)
				j++;
			if (j == n_len)
				return (s1_bis + i);
		}
		i++;
	}
	return (0);
}
