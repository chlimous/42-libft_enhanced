/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   handle_signed2.c                                   :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/03/15 23:55:59 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/09/09 01:20:30 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "ft_printf.h"

/******************************************************************************
 * @brief Manages argument length
 * 
 * @param args Arguments pointer
 * @param elem Element
 * @return intmax_t Argument integer
******************************************************************************/
intmax_t	pf_handle_length_signed(va_list args, t_pf_elem *elem)
{
	if (elem->length == HH_LOW_LEN)
		return ((signed char)va_arg(args, int));
	else if (elem->length == H_LOW_LEN)
		return ((short int)va_arg(args, int));
	else if (elem->length == L_LOW_LEN)
		return (va_arg(args, long int));
	else if (elem->length == LL_LOW_LEN)
		return (va_arg(args, long long int));
	else if (elem->length == J_LOW_LEN)
		return (va_arg(args, intmax_t));
	else if (elem->length == Z_LOW_LEN)
		return (va_arg(args, ssize_t));
	else if (elem->length == T_LOW_LEN)
		return (va_arg(args, ptrdiff_t));
	else
		return (va_arg(args, int));
}

/******************************************************************************
 * @brief Gets length of number without sign
 * 
 * @param nb Number
 * @param base Base
 * @return int Length of number
******************************************************************************/
int	pf_len_signed(intmax_t nb, char *base, t_pf_elem *elem)
{
	int			len;
	uintmax_t	tmp;

	if (nb == 0 && elem->is_dot && elem->precision == 0)
		return (0);
	len = 1;
	if (nb == INT64_MIN)
		tmp = (uintmax_t)INT64_MAX + 1;
	else if (nb < 0)
		tmp = nb * (-1);
	else
		tmp = nb;
	while (tmp / ft_strlen(base) != 0)
	{
		tmp /= ft_strlen(base);
		++len;
	}
	return (len);
}

/******************************************************************************
 * @brief Adds the number to the buffer
 * 
 * @param nb Number
 * @param base Base
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
int	pf_add_signed_nb(intmax_t nb, char *base, t_pf_elem *elem, \
		t_pf_buffer *buffer)
{
	uintmax_t	tmp;

	if (nb == 0 && elem->is_dot && elem->precision == 0)
		return (EXIT_SUCCESS);
	if (nb == INT64_MIN)
		tmp = (uintmax_t)INT64_MAX + 1;
	else if (nb < 0)
		tmp = nb * (-1);
	else
		tmp = nb;
	if (tmp / ft_strlen(base) != 0)
	{
		if (pf_add_signed_nb((intmax_t)(tmp / ft_strlen(base)), base, elem, \
					buffer) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	if (pf_add_node(buffer, base[tmp % ft_strlen(base)]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
