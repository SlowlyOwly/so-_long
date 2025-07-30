/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:17:51 by srogozin          #+#    #+#             */
/*   Updated: 2024/12/12 17:27:53 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (i < n)
	{
		return (s1[i] - s2[i]);
	}
	return (0);
}

// int main()
// {
// 	char	s1[] = "abcdef";
// 	char	s2[] = "abcdef";
// 	char	s3[] = "abdd";
// 	char	s4[] = "abbd";
// 	char	s5[] = "abc";
// 	printf("%d", ft_strncmp(s1, s2, 3));
// 	printf("\n%d", ft_strncmp(s1, s3, 3));
// 	printf("\n%d", ft_strncmp(s1, s4, 3));
// 	printf("\n%d", ft_strncmp(s1, s5, 4));
// 	return (0);
// }