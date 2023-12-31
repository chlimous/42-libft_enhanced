/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 23:24:36 by chlimous          #+#    #+#             */
/*   Updated: 2023/11/21 03:42:43 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *mem, int byte, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(mem + i) = byte;
		i++;
	}
	return (mem);
}
