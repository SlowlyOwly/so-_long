/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:31:03 by srogozin          #+#    #+#             */
/*   Updated: 2024/12/12 17:41:24 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	unsigned char	*n_ptr;
	size_t			i;

	i = 0;
	n_ptr = (unsigned char *)ptr;
	while (i < n)
	{
		n_ptr[i] = '\0';
		i++;
	}
}
