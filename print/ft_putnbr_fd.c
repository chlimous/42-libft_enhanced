/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:11:34 by chlimous          #+#    #+#             */
/*   Updated: 2024/01/01 16:11:35 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putnbr_fd(int n, int fd)
{
	ssize_t	size;
	ssize_t	ret[3];
	long	nlong;

	size = 0;
	nlong = n;
	if (nlong < 0)
	{
		ret[0] = ft_putchar_fd('-', fd);
		size += ret[0];
		nlong = -nlong;
	}
	if (nlong / 10 != 0)
	{
		ret[1] = ft_putnbr_fd(nlong / 10, fd);
		size += ret[1];
	}
	ret[2] = ft_putchar_fd(nlong % 10 + 48, fd);
	size += ret[2];
	if (ret[0] == -1 || ret[1] == -1 || ret[2] == -1)
		return (-1);
	return (size);
}
