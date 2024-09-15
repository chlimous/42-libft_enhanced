/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:11:41 by chlimous          #+#    #+#             */
/*   Updated: 2024/09/15 01:52:05 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

ssize_t	ft_putstr_fd(char *str, int fd)
{
	size_t	str_size;
	ssize_t	written;
	ssize_t	total_written;

	str_size = ft_strlen(str);
	total_written = 0;
	while ((size_t)total_written < str_size)
	{
		written = write(fd, str + total_written, str_size - total_written);
		if (written == -1)
			return (-1);
		total_written += written;
	}
	return (total_written);
}
