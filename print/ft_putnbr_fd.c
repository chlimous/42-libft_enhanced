/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:11:34 by chlimous          #+#    #+#             */
/*   Updated: 2024/01/13 02:02:57 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putnbr_fd(int n, int fd)
{
	char	*dst;
	ssize_t	written;

	dst = ft_itoa(n);
	if (!dst)
		return (-1);
	written = ft_putstr_fd(dst, fd);
	return (free(dst), written);
}
