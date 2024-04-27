/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:34:55 by chlimous          #+#    #+#             */
/*   Updated: 2024/04/26 23:34:56 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 * @brief Gets the length of exponent
 * 
 * @param nb Number
 * @return int Exponent length
******************************************************************************/
static int	len_exponent(long double nb)
{
	int	exp;
	int	exp_len;

	if (nb == 0.0)
		return (4);
	exp = 0;
	while (nb >= 10.0)
	{
		++exp;
		nb /= 10;
	}
	while (nb < 1.0)
	{
		++exp;
		nb *= 10;
	}
	exp_len = 1;
	while (exp / 10 != 0)
	{
		exp /= 10;
		++exp_len;
	}
	if (exp_len == 1)
		exp_len = 2;
	return (2 + exp_len);
}

/******************************************************************************
 * @brief Gets the length of number with %e / %E specifiers
 * 
 * @param nb 
 * @param elem 
 * @return int 
******************************************************************************/
int	len_float_e(long double nb, t_elem *elem)
{
	uintmax_t	len;

	len = 1;
	if (!elem->is_dot)
		len += 1 + DEF_PRCS_FLOAT;
	else
	{
		if (elem->precision)
			len += 1 + elem->precision;
		else if (elem->precision == 0 && elem->is_hash)
			len += 1;
	}
	len += len_exponent(nb);
	if (len < INT_MAX || (len == INT_MAX && \
				check_sign_float(nb, elem) == 0))
		return ((int)len);
	else
		return (-1);
}
