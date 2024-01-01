/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:11:25 by chlimous          #+#    #+#             */
/*   Updated: 2024/01/01 16:11:26 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putendl_fd(char *s, int fd)
{
	ssize_t	size;
	ssize_t	ret[2];

	size = 0;
	ret[0] = ft_putstr_fd(s, fd);
	size += ret[0];
	ret[1] = ft_putchar_fd('\n', fd);
	size += ret[1];
	if (ret[0] == -1 || ret[1] == -1)
		return (-1);
	return (size);
}
