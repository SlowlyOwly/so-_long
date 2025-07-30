/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:02:14 by srogozin          #+#    #+#             */
/*   Updated: 2025/01/03 22:27:39 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	str_len;

	str_len = 0;
	while (str[str_len] != '\0')
	{
		str_len++;
	}
	while (str_len >= 0)
	{
		if (str[str_len] == (char)c)
		{
			return ((char *)str + str_len);
		}
		str_len--;
	}
	return (NULL);
}

// char
// 	*ft_strrchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	while (i >= 0)
// 	{
// 		if (s[i] == (char)c)
// 			return ((char*)(s + i));
// 		i--;
// 	}
// 	return (NULL);
// }
