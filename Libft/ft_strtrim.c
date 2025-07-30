/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:04:57 by srogozin          #+#    #+#             */
/*   Updated: 2024/12/19 20:06:57 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	size_t	s1_len;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[s1_len - 1] && ft_strchr(set, s1[s1_len - 1]) && s1_len > i)
		s1_len--;
	strtrim = (char *)malloc(s1_len - i + 1);
	if (strtrim == NULL)
		return (NULL);
	ft_strlcpy(strtrim, &s1[i], s1_len - i + 1);
	return (strtrim);
}
