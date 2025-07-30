/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:07:36 by srogozin          #+#    #+#             */
/*   Updated: 2024/12/15 15:08:59 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (nmemb != 0 && size > (__SIZE_MAX__ / nmemb))
		return (NULL);
	array = (void *)malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, (nmemb * size));
	return (array);
}

// Sprawdzenie przepelnienia (czy nie przekracza rozmiaru SIZE_MAX)
// 	if (nmemb != 0 && size > (__SIZE_MAX__ / nmemb))
// 		return (NULL);
// Rezerwacja pamieci przez malloc i sprawdzenie czy pamiec przydzielona
// 	array = (void *)malloc(nmemb * size);
// 	if (array == NULL)
// 		return (NULL);
// Zerowanie zarezerwowanej pamieci
// 	ft_bzero(array, (nmemb * size));
// 	return (array);