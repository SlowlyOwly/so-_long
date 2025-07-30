/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:43:41 by srogozin          #+#    #+#             */
/*   Updated: 2025/02/19 20:06:56 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_valid(char c)
{
	const char	*valid;

	valid = "csidupxX%";
	while (*valid != '\0')
	{
		if (c == *valid)
			return (1);
		valid++;
	}
	return (0);
}

static int	conv_spec(char spec, va_list format)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += ft_putchar(va_arg(format, int));
	if (spec == 's')
		count += ft_putstr(va_arg(format, char *));
	if (spec == 'p')
		count += ft_put_ptr(va_arg(format, void *));
	if (spec == 'd' || spec == 'i')
		count += ft_prt_num(va_arg(format, int), 10);
	if (spec == 'u')
		count += ft_prt_num(va_arg(format, unsigned int), 10);
	if (spec == 'x')
		count += ft_prt_num(va_arg(format, unsigned int), 16);
	if (spec == 'X')
		count += ft_hex_upper(va_arg(format, unsigned int), 16);
	if (spec == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (ft_valid(*format))
				count += conv_spec(*format, args);
			else
			{
				count += ft_putchar('%');
				count += ft_putchar(*format);
			}
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
// int	main()
// {	
// 	int	num = 1234;
// 	int count;
// 	int x = 42;
// 	int *ptr = &x;
// 	printf("\nTest of %c%c:\n\n", '%','c');
// 	count = ft_printf("Hello in %c\n", 'C');
// 	ft_printf("Num of digits: %d\n", count);
// 	count = printf("Hello in %c\n", 'C');
// 	ft_printf("Num of digits: %d\n", count);
//	
// 	ft_printf("\nTest of %c%c and %c%c: \n\n", '%','c', '%', 's');
// 	count = ft_printf("Hello in %c %s\n", 'C', "language");
// 	ft_printf("Num of digits: %d\n", count);
// 	count = printf("Hello in %c %s\n", 'C', "language");
// 	ft_printf("Num of digits: %d\n", count);
// 	count = ft_printf("Hello in %c %s\n", 'C', (char *)NULL);
// 	ft_printf("Num of digits: %d\n", count);
// 	count = printf("Hello in %c %s\n", 'C', (char *)NULL);
// 	ft_printf("Num of digits: %d\n", count);
// 	ft_printf("Num of digits: %d\n", count);
// 	printf("Num of digits: %d\n", count);
// 	ft_printf("Num of digits: %d\n", count);
// 	printf("Num of digits: %d\n", count);
//
// 	ft_printf("\nTest of %c%c and %c%c: \n\n", '%','d', '%', 'i');
// 	count = ft_printf("Decimal of C is %d and declared num is %i\n", 'C', num);
// 	ft_printf("Num of digits: %d\n", count);
// 	count = printf("Decimal of C is %d and declared num is %i\n", 'C', num);
// 	printf("Num of digits: %d\n", count);
//
// 	ft_printf("\nTest of %c sign: \n\n", '%');
// 	count = ft_printf("Give a %d%% of yourself\n", 100);
// 	ft_printf("Num of digits: %d\n", count);
// 	count = printf("Give a %d%% of yourself\n", 100);
// 	ft_printf("Num of digits: %d\n", count);
//
// 	ft_printf("\nTest of %c%c: \n\n", '%','u');
// 	count = ft_printf("Unsigned dec of -100 is %u\n", -100);
// 	ft_printf("Num of digits: %d\n", count);
// 	count = printf("Unsigned dec of -100 is %u\n", -100);
// 	ft_printf("Num of digits: %d\n", count);
// 	count = ft_printf("Unsigned dec of 15 is %u\n", 15);
// 	ft_printf("Num of digits: %d\n", count);
// 	count = printf("Unsigned dec of 15 is %u\n", 15);
// 	ft_printf("Num of digits: %d\n", count);
// 	count = ft_printf("Unsigned dec of 0 is %u\n", 0);
// 	ft_printf("Num of digits: %d\n", count);
// 	count = printf("Unsigned dec of 0 is %u\n", 0);
// 	ft_printf("Num of digits: %d\n", count);
//
// 	ft_printf("\nTest of %c%c: \n\n", '%','p');
// 	count = ft_printf("Adres of x: %p\n", &x);
// 	ft_printf("Num of digits: %d\n", count);
// 	count = printf("Adres of x: %p\n", &x);
// 	ft_printf("Num of digits: %d\n", count);
// 	count = ft_printf("Adres of x: %p\n", ptr);
// 	ft_printf("Num of digits: %d\n", count);
// 	count = printf("Adres of x: %p\n", ptr);
// 	ft_printf("Num of digits: %d\n", count);
// 	count = ft_printf("Adres of x: %p\n", (char *)NULL);
// 	ft_printf("Num of digits: %d\n", count);
// 	count = printf("Adres of x: %p\n", (char *)NULL);
// 	ft_printf("Num of digits: %d\n", count);
//
// 	ft_printf("\nTest of %c%c: \n\n", '%','x');
// 	count = ft_printf("Lower hex num: %x\n", num);
// 	ft_printf("Num of digits: %d\n", count);
// 	count = printf("Lower hex num: %x\n", num);
// 	ft_printf("Num of digits: %d\n", count);
// 	count = ft_printf("Lower hex num: %x\n", -123);
// 	ft_printf("Num of digits: %d\n", count);
// 	count = printf("Lower hex num: %x\n", -123);
// 	ft_printf("Num of digits: %d\n", count);
//
// 	ft_printf("\nTest of %c%c: \n\n", '%','X');
// 	count = ft_printf("Upper hex num: %X\n", num);
// 	ft_printf("Num of digits: %d\n", count);
// 	count = printf("Upper hex num: %X\n", num);
// 	ft_printf("Num of digits: %d\n", count);
// 	count = ft_printf("Upper hex num: %X\n", -123);
// 	ft_printf("Num of digits: %d\n", count);
// 	count =printf("Upper hex num: %X\n", -123);
// 	ft_printf("Num of digits: %d\n", count);
//
// 	ft_printf("\nTest of len: \n\n");
// 	ft_printf("%d\n", ft_printf("test "));
// 	printf("%d\n", printf("test "));
// 	return(0);
// }