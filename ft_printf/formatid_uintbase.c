/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatid_uintbase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:52:57 by chlimous          #+#    #+#             */
/*   Updated: 2023/12/31 04:36:25 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	formatid_uintbase(unsigned int nb, char *base, size_t size)
{
	if (nb / ft_strlen(base) != 0)
		size = formatid_uintbase(nb / ft_strlen(base), base, size);
	ft_putchar_fd(base[nb % ft_strlen(base)], 1);
	return (size + 1);
}
