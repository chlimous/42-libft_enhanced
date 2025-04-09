/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:24:39 by chlimous          #+#    #+#             */
/*   Updated: 2025/04/09 10:02:11 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_str_realloc(char *str, size_t size)
{
	char	*new;
	int		cpy_size;

	new = malloc(size);
	if (!new)
		return (NULL);
	cpy_size = size;
	if (ft_strlen(str) + 1 < size)
		cpy_size = ft_strlen(str) + 1;
	ft_memcpy(new, str, cpy_size);
	free(str);
	return (new);
}
