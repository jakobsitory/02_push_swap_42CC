/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:59:06 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:24:22 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Counts the number of words in a string separated by a specific character.
 * 
 * @param s A pointer to the input string.
 * @param c The delimiter character.
 * @return The number of words in the string.
 */
int	ft_words_in_str(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

/**
 * Frees all allocated memory in an array of strings.
 * 
 * @param arr A pointer to the array of strings to be freed.
 */
void	ft_freeall(char **arr)
{
	int	i;

	i = 0;
	while (arr)
		free(arr[i++]);
	free (arr);
}

/**
 * Allocates memory for and copies a substring into a new string.
 * 
 * @param pos A pointer to the start position of the substring in the input string.
 * @param len The length of the substring to copy.
 * @param words A pointer to an array of previously allocated strings, to be freed in case of an error.
 * @return A pointer to the newly allocated string, or NULL if memory allocation fails.
 */
char	*ft_writestr(char *pos, int len, char **words)
{
	char	*word;

	word = (char *) malloc (len + 1);
	if (word == 0)
	{
		ft_freeall(words);
		return (0);
	}
	ft_strlcpy(word, pos, len + 1);
	return (word);
}

/**
 * Finds the first occurrence of a character different from `c` in a string.this character. If all characters in `s` match `c` or if `s`
 * is empty, the function returns `NULL`.
 * 
 * @param s A pointer to the string to be searched.
 * @param c The character to be compared against, cast to an `int`.
 * @return A pointer to the first character in `s` that is not `c`, or `NULL` if no such character exists.
 */
char	*ft_strnchr(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != (char) c)
			return (&s[i]);
		i++;
	}
	return (0);
}

/**
 * Splits a string into an array of strings based on a delimiter character.
 * 
 * @param s The input string to be split.
 * @param c The delimiter character.
 * @return A pointer to the array of strings, or `NULL` if an error occurs.
 */
char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	char	**words;
	int		wordlen;
	char	*pos;

	count = ft_words_in_str(s, c);
	words = (char **) malloc (++count * sizeof(char *));
	if (!words)
		return (0);
	pos = (char *) s;
	i = 0;
	wordlen = 0;
	while (i + 1 < count)
	{
		pos = ft_strnchr(&pos[wordlen], c);
		if (ft_strchr(pos, c))
			wordlen = ft_strchr(pos, c) - pos;
		else
			wordlen = ft_strlen(pos);
		words[i] = ft_writestr(pos, wordlen, words);
		i++;
	}
	words[count] = 0;
	return (words);
}
