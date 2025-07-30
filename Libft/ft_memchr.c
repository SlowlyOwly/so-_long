/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:07:48 by srogozin          #+#    #+#             */
/*   Updated: 2025/01/02 18:56:39 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*n_str;
	size_t			i;

	i = 0;
	n_str = (unsigned char *)s;
	while (i < n)
	{
		if (n_str[i] == (unsigned char)c)
		{
			return ((void *)&n_str[i]);
		}
		i++;
	}
	return (NULL);
}
