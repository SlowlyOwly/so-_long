/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:21:21 by srogozin          #+#    #+#             */
/*   Updated: 2024/12/12 17:27:46 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t num)
{
	unsigned char	*n_ptr;
	size_t			i;

	n_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		n_ptr[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}
