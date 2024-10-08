/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:17:49 by chlimous          #+#    #+#             */
/*   Updated: 2024/09/15 02:47:47 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	substr_size(char const *s, size_t start, size_t len)
{
	size_t		size;

	if (start >= ft_strlen(s))
		return (0);
	size = ft_strlen(s + start);
	if (size > len)
		size = len;
	return (size);
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char		*str;
	size_t		size;

	size = substr_size(s, start, len);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	*str = '\0';
	if (start < ft_strlen(s))
		ft_strlcpy(str, s + start, size + 1);
	return (str);
}
