/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:36:10 by srogozin          #+#    #+#             */
/*   Updated: 2024/12/12 17:27:56 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
	{
		c = c + 32;
	}
	return (c);
}

// int main()
// {
// 	printf("%c \n", ft_tolower('C'));
// 	printf("%c \n", ft_tolower('A'));
// 	printf("%c \n", ft_tolower('Z'));
// }