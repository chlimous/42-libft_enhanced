/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/04 17:58:46 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/09/15 05:09:48 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *src, size_t size)
{
	char	*dest;

	if (ft_strlen(src) < size)
		size = ft_strlen(src);
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	return ((char *)ft_memcpy(dest, src, size));
}
