/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:34:41 by chlimous          #+#    #+#             */
/*   Updated: 2024/04/26 23:34:43 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/******************************************************************************
 * @brief Gets length of integer part
 * 
 * @param nb Number
 * @return int Length of integer part
******************************************************************************/
static int	len_float_int(long double nb)
{
	int			len;
	long double	multiplier;
	long double	tmp;
	int			digit;

	len = 0;
	multiplier = 1.0;
	tmp = nb;
	while (tmp >= 10.0 || tmp <= -10.0)
	{
		multiplier *= 10;
		tmp /= 10;
	}
	while (multiplier >= 1.0)
	{
		++len;
		digit = (int)(nb / multiplier);
		nb -= digit * multiplier;
		multiplier /= 10;
	}
	return (len);
}

/******************************************************************************
 * @brief Gets the length of number with %f / %F specifiers
 * 
 * @param nb Number
 * @param elem Element
 * @return int Length
******************************************************************************/
int	pf_len_float_f(long double nb, t_pf_elem *elem)
{
	uintmax_t	len;

	len = len_float_int(nb);
	if (!elem->is_dot)
		len += 1 + DEF_PRCS_FLOAT;
	else
	{
		if (elem->precision)
			len += 1 + elem->precision;
		else if (elem->precision == 0 && elem->is_hash)
			len += 1;
	}
	if (len < INT_MAX || (len == INT_MAX && \
				pf_check_sign_float(nb, elem) == 0))
		return ((int)len);
	else
		return (-1);
}

/******************************************************************************
 * @brief Adds the integer part of the number to the buffer
 * 
 * @param nb Number
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
static int	add_float_int(long double *nb, t_pf_buffer *buffer)
{
	long double	multiplier;
	long double	tmp;
	int			digit;

	multiplier = 1.0;
	tmp = *nb;
	while (tmp >= 10.0 || tmp <= -10.0)
	{
		multiplier *= 10;
		tmp /= 10;
	}
	while (multiplier >= 1.0)
	{
		digit = (int)(*nb / multiplier);
		if (pf_add_node(buffer, BASE_10[pf_abs_int(digit)]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		*nb -= digit * multiplier;
		multiplier /= 10;
	}
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Adds the decimal part of the number to the buffer
 * 
 * @param nb Number
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
int	pf_add_float_dec(long double nb, t_pf_elem *elem, t_pf_buffer *buffer)
{
	int	precision;
	int	digit;

	if (!elem->is_dot)
		precision = DEF_PRCS_FLOAT;
	else
		precision = elem->precision;
	while (precision)
	{
		nb *= 10;
		digit = (int)nb;
		if (pf_add_node(buffer, BASE_10[pf_abs_int(digit)]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		nb -= digit;
		--precision;
	}
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Adds the number to the buffer with %f / %F specifiers
 * 
 * @param nb Number
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
int	pf_add_float_f(long double nb, t_pf_elem *elem, t_pf_buffer *buffer)
{
	if (add_float_int(&nb, buffer) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (!(elem->is_dot && elem->precision == 0 && !elem->is_hash))
	{
		if (pf_add_node(buffer, '.') == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (pf_add_float_dec(nb, elem, buffer) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
