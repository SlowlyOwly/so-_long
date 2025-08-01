/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:51:37 by srogozin          #+#    #+#             */
/*   Updated: 2025/08/01 10:27:50 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prt_num(long n, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		count++;
	}
	if (n < base)
		return (count + ft_putchar(symbols[n]));
	count += ft_prt_num(n / base, base);
	count += ft_prt_num(n % base, base);
	return (count);
}

int	ft_hex_upper(long n, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		count = 1;
		n = -n;
		ft_putchar('-');
	}
	if (n < base)
		return (ft_putchar(symbols[n]));
	else
	{
		count = ft_hex_upper(n / base, base);
		return (count + ft_hex_upper(n % base, base));
	}
}

int	ft_prt_num_ptr(unsigned long n, unsigned int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	// if (n < 0)
	// {
	// 	ft_putchar('-');
	// 	n = -n;
	// 	count++;
	// }
	if (n < base)
		return (count + ft_putchar(symbols[n]));
	count += ft_prt_num(n / base, base);
	count += ft_prt_num(n % base, base);
	return (count);
}

int	ft_put_ptr(void *ptr)
{
	int			count;
	uintptr_t	ptr_adress;

	ptr_adress = (uintptr_t)ptr;
	if (ptr == NULL)
	{
		ft_putstr("(nil)");
		return (5);
	}
	count = ft_putstr("0x");
	count += ft_prt_num_ptr((uintptr_t)ptr_adress, 16);
	return (count);
}
