/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:01:19 by srogozin          #+#    #+#             */
/*   Updated: 2024/12/31 12:11:37 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

// int main()
// {
// 	// Testy funkcji ft_putnbr_fd
//
// 	// Wypisanie liczby dodatniej
// 	ft_putnbr_fd(1234, 1);
// 	write(1, "\n", 1);  // Nowa linia dla rozdzielenia wyników
//
// 	// Wypisanie liczby ujemnej
// 	ft_putnbr_fd(-5678, 1);
// 	write(1, "\n", 1);
//
// 	// Wypisanie zera
// 	ft_putnbr_fd(0, 1);
// 	write(1, "\n", 1);
//
// 	// Wypisanie liczby INT_MIN
// 	ft_putnbr_fd(-2147483648, 1);
// 	write(1, "\n", 1);
//
// 	// Wypisanie liczby 1200
// 	ft_putnbr_fd(1200, 1);
// 	write(1, "\n", 1);
//
// 	return 0;
// }
