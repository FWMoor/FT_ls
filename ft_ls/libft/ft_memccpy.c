/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 08:32:21 by fremoor           #+#    #+#             */
/*   Updated: 2019/05/22 14:20:44 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	char		*s1;
	const char	*s2;

	s1 = (char *)str1;
	s2 = (char *)str2;
	while (n)
	{
		*s1 = *s2;
		if (*s2 == (char)c)
			return (s1 + 1);
		s1++;
		s2++;
		n--;
	}
	return (NULL);
}
