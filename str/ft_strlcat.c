/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/08 17:35:54 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/09/15 02:37:27 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_size;

	i = 0;
	if (dest)
		i = ft_strlen(dest);
	dest_size = i + (size_t)ft_strlen(src);
	if (size <= i)
		return (ft_strlen(src) + size);
	while (i < size - 1 && *src)
	{
		dest[i] = *src;
		++src;
		++i;
	}
	dest[i] = '\0';
	return (dest_size);
}
