/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:43:08 by srogozin          #+#    #+#             */
/*   Updated: 2025/01/03 23:23:54 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)(str + i));
	return (NULL);
}

// int main()
// {
// 	char str[] = "hello world";
//
// 	printf("%s \n", ft_strchr(str, 'h'));
// 	printf("%s \n", strchr(str, 'h'));
// 	printf("%s \n", ft_strchr(str, 'o'));
// 	printf("%s \n", strchr(str, 'o'));
// 	printf("%s \n", ft_strchr(str, 'z'));
//     printf("%s \n", strchr(str, 'z'));
// }