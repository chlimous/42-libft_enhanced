/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:11:25 by chlimous          #+#    #+#             */
/*   Updated: 2024/09/15 01:50:09 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

ssize_t	ft_putendl_fd(char *str, int fd)
{
	char	*dst;
	ssize_t	written;
	size_t	str_size;

	str_size = ft_strlen(str);
	dst = malloc(sizeof(char) * (str_size + 2));
	if (!dst)
		return (-1);
	ft_memcpy(dst, str, str_size);
	dst[str_size] = '\n';
	dst[str_size + 1] = '\0';
	written = ft_putstr_fd(dst, fd);
	return (free(dst), written);
}
