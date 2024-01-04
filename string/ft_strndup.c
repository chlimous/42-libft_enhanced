/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:58:46 by chlimous          #+#    #+#             */
/*   Updated: 2024/01/04 18:09:39 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t size)
{
	char	*dest;
	size_t	i;

	if (ft_strlen(src) < size)
		size = ft_strlen(src);
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
