/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/03/15 21:54:31 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/09/09 01:20:58 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 * @brief Manages argument length
 * 
 * @param args Arguments pointer
 * @param elem Element
 * @return uintmax_t Argument integer
******************************************************************************/
uintmax_t	pf_handle_length_unsigned(va_list args, t_pf_elem *elem)
{
	if (elem->length == HH_LOW_LEN)
		return ((unsigned char)va_arg(args, int));
	else if (elem->length == H_LOW_LEN)
		return ((unsigned short int)va_arg(args, int));
	else if (elem->length == LL_LOW_LEN)
		return (va_arg(args, unsigned long long int));
	else if (elem->length == L_LOW_LEN)
		return (va_arg(args, unsigned long int));
	else if (elem->length == J_LOW_LEN)
		return (va_arg(args, uintmax_t));
	else if (elem->length == Z_LOW_LEN)
		return (va_arg(args, size_t));
	else if (elem->length == T_LOW_LEN)
		return (va_arg(args, ptrdiff_t));
	else
		return (va_arg(args, unsigned int));
}

/******************************************************************************
 * @brief Executes conversion for '-' flag
 * 
 * @param nb Number
 * @param base Base
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
static int	handle_minus(uintmax_t nb, char *base, t_pf_elem *elem, \
		t_pf_buffer *buffer)
{
	int	prefix_len_precision;
	int	prefix_len_width;

	prefix_len_precision = pf_check_prefix_precision(nb, elem);
	prefix_len_width = pf_check_prefix_width(nb, elem);
	if (pf_add_prefix(nb, elem, buffer) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (elem->is_dot)
	{
		if (pf_fill_width(buffer, elem->precision - (pf_len_unsigned(nb, \
		base, elem) + prefix_len_precision), '0') == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	if (pf_add_unsigned_nb(nb, base, elem, buffer) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (pf_fill_width(buffer, elem->width - MAX(elem->precision \
	- pf_check_prefix_precision(nb, elem) + prefix_len_width, \
	pf_len_unsigned(nb, base, elem) + prefix_len_width), ' ') == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Executes conversion
 * 
 * @param nb Number
 * @param base Base
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
static int	handle_default(uintmax_t nb, char *base, t_pf_elem *elem, \
		t_pf_buffer *buffer)
{
	if (elem->is_zero && !elem->is_dot && base[0] == '0')
	{
		if (pf_add_prefix(nb, elem, buffer) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (pf_fill_width(buffer, elem->width - (pf_len_unsigned(nb, base, \
				elem) + pf_check_prefix_width(nb, elem)), '0') == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		if (pf_fill_width(buffer, elem->width - MAX(elem->precision \
			- pf_check_prefix_precision(nb, elem) + \
			pf_check_prefix_width(nb, elem), pf_len_unsigned(nb, base, elem) \
			+ pf_check_prefix_width(nb, elem)), ' ') == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (pf_add_prefix(nb, elem, buffer) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	if (pf_fill_width(buffer, elem->precision - (pf_len_unsigned(nb, base, \
			elem) + pf_check_prefix_precision(nb, elem)), '0') == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (pf_add_unsigned_nb(nb, base, elem, buffer) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Executes conversion for unsigned integer
 * 
 * @param nb Number
 * @param base Base
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
int	pf_handle_unsigned(uintmax_t nb, char *base, t_pf_elem *elem, \
		t_pf_buffer *buffer)
{
	if (elem->is_minus)
	{
		if (handle_minus(nb, base, elem, buffer) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		if (handle_default(nb, base, elem, buffer) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
