/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:03:03 by srogozin          #+#    #+#             */
/*   Updated: 2025/01/02 19:33:26 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_wordcount(const char *str, char c)
{
	size_t	str_i;
	size_t	words_count;

	str_i = 0;
	words_count = 0;
	if (str == NULL)
		return (0);
	while (str[str_i] != '\0')
	{
		while (str[str_i] == c)
			str_i++;
		if (str[str_i] != '\0')
			words_count++;
		while (str[str_i] != c && str[str_i] != '\0')
			str_i++;
	}
	return (words_count);
}

static char	*ft_free_aloc(char **str, size_t i)
{
	while (i > 0)
		free (str[--i]);
	free (str);
	return (NULL);
}

static void	*ft_words(char **sp_w, char const *s, char c, size_t w_num)
{
	size_t	split_i;
	size_t	i;
	size_t	start_w;

	split_i = 0;
	i = 0;
	while (s[i] != '\0' && split_i < w_num)
	{
		while (s[i] == c)
			i++;
		start_w = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		sp_w[split_i] = (char *)malloc(i - start_w + 1);
		if (sp_w[split_i] == NULL)
		{
			ft_free_aloc(sp_w, split_i);
			return (NULL);
		}
		ft_strlcpy(sp_w[split_i], &s[start_w], i - start_w + 1);
		split_i++;
	}
	sp_w[split_i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**split_words;
	size_t	words_count;

	if (s == NULL)
		return (NULL);
	words_count = ft_wordcount(s, c);
	split_words = (char **)malloc((words_count + 1) * sizeof(char *));
	if (split_words == NULL)
		return (NULL);
	ft_words(split_words, s, c, words_count);
	return (split_words);
}

// size_t	ft_strlcpy(char *dest, const char *src, size_t size)
// {
// 	size_t	i;
// 	size_t	j;
//
// 	i = 0;
// 	j = 0;
// 	while (src[i] != '\0')
// 	{
// 		i++;
// 	}
// 	if (size == 0)
// 	{
// 		return (i);
// 	}
// 	while (src[j] != '\0' && j < size - 1)
// 	{
// 		dest[j] = src[j];
// 		j++;
// 	}
// 	dest[j] = '\0';
// 	return (i);
// }
// char **ft_split(char const *s, char c);
//
// // Helper function to free the split result
// void free_split_result(char **result) {
//     if (!result)
//         return;
//     for (int i = 0; result[i]; i++)
//         free(result[i]);
//     free(result);
// }
//
// // Helper function to compare split results
// bool compare_splits(char **result, char **expected) {
//     if (!result && !expected)
//         return true;
//     if (!result || !expected)
//         return false;
//   
//     int i = 0;
//     while (result[i] && expected[i]) {
//         if (strcmp(result[i], expected[i]) != 0)
//             return false;
//         i++;
//     }
//     return result[i] == expected[i]; // Both should be NULL
// }
//
// void print_split_result(char **result) {
//     if (!result) {
//         printf("(NULL)\n");
//         return;
//     }
//     printf("[");
//     for (int i = 0; result[i]; i++) {
//         printf("\"%s\"", result[i]);
//         if (result[i + 1])
//             printf(", ");
//     }
//     printf("]\n");
// }
//
// // Test functions
// void test_basic_split(void) {
//     printf("\nTest 1: Basic split with spaces\n");
//     char *str = "hello world test";
//     char **result = ft_split(str, ' ');
//     char *expected[] = {"hello", "world", "test", NULL};
//   
//     printf("Input: \"%s\"\n", str);
//     printf("Expected: [\"hello\", \"world\", \"test\"]\n");
//     printf("Got:      ");
//     print_split_result(result);
//   
//     if (compare_splits(result, expected))
//         printf("✅ Test passed\n");
//     else
//         printf("❌ Test failed\n");
//   
//     free_split_result(result);
// }
//
// void test_multiple_delimiters(void) {
//     printf("\nTest 2: Multiple consecutive delimiters\n");
//     char *str = "hello   world  test";
//     char **result = ft_split(str, ' ');
//     char *expected[] = {"hello", "world", "test", NULL};
//   
//     printf("Input: \"%s\"\n", str);
//     printf("Expected: [\"hello\", \"world\", \"test\"]\n");
//     printf("Got:      ");
//     print_split_result(result);
//   
//     if (compare_splits(result, expected))
//         printf("✅ Test passed\n");
//     else
//         printf("❌ Test failed\n");
//   
//     free_split_result(result);
// }
//
// void test_empty_string(void) {
//     printf("\nTest 3: Empty string\n");
//     char *str = "";
//     char **result = ft_split(str, ' ');
//     char *expected[] = {NULL};
//   
//     printf("Input: \"%s\"\n", str);
//     printf("Expected: []\n");
//     printf("Got:      ");
//     print_split_result(result);
//   
//     if (compare_splits(result, expected))
//         printf("✅ Test passed\n");
//     else
//         printf("❌ Test failed\n");
//   
//     free_split_result(result);
// }
//
// void test_no_delimiter(void) {
//     printf("\nTest 4: String with no delimiter\n");
//     char *str = "hello";
//     char **result = ft_split(str, ' ');
//     char *expected[] = {"hello", NULL};
//   
//     printf("Input: \"%s\"\n", str);
//     printf("Expected: [\"hello\"]\n");
//     printf("Got:      ");
//     print_split_result(result);
//   
//     if (compare_splits(result, expected))
//         printf("✅ Test passed\n");
//     else
//         printf("❌ Test failed\n");
//   
//     free_split_result(result);
// }
//
// void test_null_input(void) {
//     printf("\nTest 5: NULL input\n");
//     char *str = NULL;
//     char **result = ft_split(str, ' ');
//   
//     printf("Input: NULL\n");
//     printf("Expected: (NULL)\n");
//     printf("Got:      ");
//     print_split_result(result);
//   
//     if (result == NULL)
//         printf("✅ Test passed\n");
//     else
//         printf("❌ Test failed\n");
//   
//     free_split_result(result);
// }
//
// void test_different_delimiter(void) {
//     printf("\nTest 6: Different delimiter (comma)\n");
//     char *str = "one,two,three,four";
//     char **result = ft_split(str, ',');
//     char *expected[] = {"one", "two", "three", "four", NULL};
//   
//     printf("Input: \"%s\"\n", str);
//     printf("Expected: [\"one\", \"two\", \"three\", \"four\"]\n");
//     printf("Got:      ");
//     print_split_result(result);
//   
//     if (compare_splits(result, expected))
//         printf("✅ Test passed\n");
//     else
//         printf("❌ Test failed\n");
//   
//     free_split_result(result);
// }
//
// int main(void) {
//     printf("Running tests for ft_split function...\n");
//   
//     test_basic_split();
//     test_multiple_delimiters();
//     test_empty_string();
//     test_no_delimiter();
//     test_null_input();
//     test_different_delimiter();
//   
//     return 0;
// }