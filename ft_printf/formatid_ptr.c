/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatid_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:21:52 by chlimous          #+#    #+#             */
/*   Updated: 2023/12/31 04:36:43 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	formatid_ptr(void *ptr, size_t size)
{
	char	*base;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	if (!size)
	{
		ft_putstr_fd("0x", 1);
		size += 2;
	}
	base = "0123456789abcdef";
	if ((size_t)ptr / 16 != 0)
		size = formatid_ptr((void *)((size_t)ptr / 16), size);
	ft_putchar_fd(base[(size_t)ptr % 16], 1);
	return (size + 1);
}
