/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/15 21:47:56 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/12/13 12:12:30 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *src, int size)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	word_size(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	count_words(const char *str, char c)
{
	int	words;

	words = 0;
	while (*str)
	{
		if (*str && *str != c)
		{
			words++;
			str += word_size(str, c);
		}
		while (*str && *str == c)
			str++;
	}
	return (words);
}

static void	free_matrix(char **strs, int size)
{
	int	i;

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

char	**ft_split(char const *str, char c)
{
	char	**strs;
	int		i;

	strs = malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!strs)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str && *str != c)
		{
			strs[i] = ft_strndup(str, word_size(str, c));
			if (!strs[i])
			{
				free_matrix(strs, i);
				return (NULL);
			}
			str += word_size(str, c);
			i++;
		}
		while (*str && *str == c)
			str++;
	}
	strs[i] = 0;
	return (strs);
}
