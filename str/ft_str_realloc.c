/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:24:39 by chlimous          #+#    #+#             */
/*   Updated: 2025/04/09 01:24:40 by chlimous         ###   ########.fr       */
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
	if (size <= ft_strlen(str) + 1)
		cpy_size = size;
	else
		cpy_size = ft_strlen(str) + 1;
	ft_memcpy(new, str, cpy_size);
	free(str);
	return (new);
}
