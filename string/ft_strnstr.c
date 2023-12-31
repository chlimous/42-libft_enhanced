/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/25 00:18:30 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/11/21 20:19:07 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = ft_strlen(little);
	if (!size)
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		while ((big + i)[j] == little[j] && (i + j) < len)
		{
			if (j == size - 1)
				return ((char *)(big + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
