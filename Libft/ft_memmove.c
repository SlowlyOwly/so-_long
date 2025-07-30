/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:20:26 by srogozin          #+#    #+#             */
/*   Updated: 2024/12/12 17:27:45 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src || n == 0)
	{
		return (dest);
	}
	if (dest < src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	if (dest > src)
	{
		while (n > 0)
		{
			n--;
			((unsigned char *)dest)[n] = ((const unsigned char *)src)[n];
		}
	}
	return (dest);
}

// int main()
// {
// 	char str1[] = "Testing";
// 	char str2[] = "Testing";
// 	memmove(str1 + 3, str1, 4);
// 	ft_memmove(str2 + 3, str2, 4);
// 	printf("%s \n", str1);
// 	printf("%s \n", str2);
// }