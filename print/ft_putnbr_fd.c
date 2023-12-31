/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:25:18 by chlimous          #+#    #+#             */
/*   Updated: 2023/10/28 21:31:09 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nlong;

	nlong = n;
	if (nlong < 0)
	{
		ft_putchar_fd('-', fd);
		nlong = -nlong;
	}
	if (nlong / 10 != 0)
		ft_putnbr_fd(nlong / 10, fd);
	ft_putchar_fd(nlong % 10 + 48, fd);
}
