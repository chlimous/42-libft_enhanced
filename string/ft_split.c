/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/15 21:47:56 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/01/04 18:36:09 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static bool	is_sep(char c, char const *sep_charset)
{
	while (*sep_charset)
	{
		if (c == *sep_charset)
			return (true);
		sep_charset++;
	}
	return (false);
}

static int	word_size(char const *str, char const *sep_charset)
{
	size_t	i;

	i = 0;
	while (str[i] && !is_sep(str[i], sep_charset))
		i++;
	return (i);
}

static int	count_words(char const *str, char const *sep_charset)
{
	size_t	words;

	words = 0;
	while (*str)
	{
		if (*str && !is_sep(*str, sep_charset))
		{
			words++;
			str += word_size(str, sep_charset);
		}
		while (*str && is_sep(*str, sep_charset))
			str++;
	}
	return (words);
}

static void	free_matrix(char **strs, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	free(strs);
	strs = NULL;
}

char	**ft_split(char const *str, char const *sep_charset)
{
	char		**strs;
	size_t		i;

	strs = malloc(sizeof(char *) * (count_words(str, sep_charset) + 1));
	if (!strs)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str && !is_sep(*str, sep_charset))
		{
			strs[i] = ft_strndup(str, word_size(str, sep_charset));
			if (!strs[i])
			{
				free_matrix(strs, i);
				return (NULL);
			}
			str += word_size(str, sep_charset);
			i++;
		}
		while (*str && is_sep(*str, sep_charset))
			str++;
	}
	strs[i] = 0;
	return (strs);
}
