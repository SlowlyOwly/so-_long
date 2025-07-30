/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:54:24 by srogozin          #+#    #+#             */
/*   Updated: 2025/02/09 13:13:07 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);

int		ft_putchar(int c);

int		ft_putstr(char *str);

int		ft_prt_num(long n, int base);

int		ft_hex_upper(long n, int base);

int		ft_put_ptr(void *ptr);

int		ft_prt_num_ptr(unsigned long n, unsigned int base);

#endif
