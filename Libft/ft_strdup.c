/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:21:07 by srogozin          #+#    #+#             */
/*   Updated: 2024/12/15 16:01:13 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		size;
	char	*array;

	size = ft_strlen(s);
	array = (char *)malloc(size + 1);
	if (array == NULL)
		return (NULL);
	ft_strlcpy(array, s, size + 1);
	return (array);
}
