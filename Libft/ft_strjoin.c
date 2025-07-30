/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:44:47 by srogozin          #+#    #+#             */
/*   Updated: 2025/01/02 19:06:25 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	concat = (char *)malloc(s1_len + s2_len + 1);
	if (concat == NULL)
		return (NULL);
	ft_strlcpy(concat, s1, s1_len +1);
	ft_strlcpy(concat + s1_len, s2, s2_len + 1);
	return (concat);
}

// int	main(void)
// {
// 	char	*result;
//
// 	// Test 1: Normalne przypadki
// 	printf("Test 1: Normalne przypadki\n");
// 	result = ft_strjoin("Hello, ", "world!");
// 	printf("Oczekiwane: Hello, world!\n");
// 	printf("Wynik: %s\n", result);
// 	free(result);
//
// 	// Test 2: Jeden z ciągów pusty
// 	printf("\nTest 2: Jeden z ciągów pusty\n");
// 	result = ft_strjoin("", "Test");
// 	printf("Oczekiwane: Test\n");
// 	printf("Wynik: %s\n", result);
// 	free(result);
//
// 	result = ft_strjoin("Test", "");
// 	printf("Oczekiwane: Test\n");
// 	printf("Wynik: %s\n", result);
// 	free(result);
//
// 	// Test 3: Oba ciągi puste
// 	printf("\nTest 3: Oba ciągi puste\n");
// 	result = ft_strjoin("", "");
// 	printf("Oczekiwane: <pusty ciąg>\n");
// 	printf("Wynik: '%s'\n", result);
// 	free(result);
//
// 	// Test 4: NULL jako któryś z argumentów
// 	printf("\nTest 4: NULL jako któryś z argumentów\n");
// 	result = ft_strjoin(NULL, "world");
// 	printf("Oczekiwane: NULL\n");
// 	printf("Wynik: %s\n", result);
//
// 	result = ft_strjoin("Hello", NULL);
// 	printf("Oczekiwane: NULL\n");
// 	printf("Wynik: %s\n", result);
//
// 	return (0);
// }