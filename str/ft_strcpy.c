/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/07 00:33:41 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/09/15 02:20:06 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
