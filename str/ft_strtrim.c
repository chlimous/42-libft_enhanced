/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:04:10 by chlimous          #+#    #+#             */
/*   Updated: 2024/09/15 02:47:19 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_set_char(const char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		++set;
	}
	return (0);
}

static int	is_right_part(char const *s1, char const *set)
{
	while (*s1)
	{
		if (!is_set_char(*s1, set))
			return (0);
		++s1;
	}
	return (1);
}

static size_t	res_str_size(char const *s1, char const *set)
{
	size_t	trimmed;
	size_t	i;

	i = 0;
	while (s1[i] && is_set_char(s1[i], set))
		++i;
	trimmed = i;
	while (s1[i] && !is_right_part(s1 + i, set))
		++i;
	while (s1[i])
	{
		++trimmed;
		++i;
	}
	return (ft_strlen(s1) - trimmed);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;

	str = malloc(sizeof(char) * res_str_size(s1, set) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (*s1 && is_set_char(*s1, set))
		++s1;
	while (*s1 && !is_right_part(s1, set))
	{
		str[i] = *s1;
		++s1;
		++i;
	}
	str[i] = '\0';
	return (str);
}
