/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 11:56:40 by srogozin          #+#    #+#             */
/*   Updated: 2024/12/29 10:05:45 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_len(int n)
{
	size_t			num_len;
	unsigned int	un_n;

	num_len = 0;
	if (n <= 0)
		num_len++;
	if (n < 0)
		un_n = -n;
	else
		un_n = n;
	while (un_n > 0)
	{
		num_len++;
		un_n = un_n / 10;
	}
	return (num_len);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			num_len;
	unsigned int	un_n;

	num_len = ft_num_len(n);
	str = (char *)malloc(num_len + 1);
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[num_len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		un_n = -n;
	}
	else
		un_n = n;
	while (un_n > 0)
	{
		str[num_len - 1] = un_n % 10 + '0';
		num_len--;
		un_n = un_n / 10;
	}
	return (str);
}

// int main()
// {
// 	int num1 = 42;
// 	int num2 = -42;
// 	int num3 = 0;
// 	int num4 = -2147483648;
// 	int num5 = 2147483647;
// 	printf("%s \n", ft_itoa(num1));
// 	printf("%s \n", ft_itoa(num2));
// 	printf("%s \n", ft_itoa(num3));
// 	printf("%s \n", ft_itoa(num4));
// 	printf("%s \n", ft_itoa(num5));
// 	return(0);
// }