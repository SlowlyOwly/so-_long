/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:29:31 by srogozin          #+#    #+#             */
/*   Updated: 2025/02/21 11:16:57 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	str_len;
	char	*str_dupl;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	str_dupl = malloc(str_len + 1);
	if (str_dupl == NULL)
		return (NULL);
	str_dupl[str_len] = '\0';
	while (s[i] != '\0')
	{
		str_dupl[i] = s[i];
		i++;
	}
	return (str_dupl);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_string;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_string = malloc(s1_len + s2_len + 1);
	if (new_string == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new_string[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		new_string[i++] = s2[j++];
	new_string[i] = '\0';
	return (new_string);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	substr_i;
	size_t	substr_len;
	size_t	s_len;

	substr_i = 0;
	s_len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start >= s_len)
		return (ft_strdup(""));
	if ((s_len - start) < len)
		substr_len = s_len - start;
	else
		substr_len = len;
	substr = (char *)malloc(substr_len + 1);
	if (substr == NULL)
		return (NULL);
	while (s[start + substr_i] != '\0' && substr_i < substr_len)
	{
		substr[substr_i] = s[start + substr_i];
		substr_i++;
	}
	substr[substr_i] = '\0';
	return (substr);
}
