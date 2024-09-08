/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   handle_signed.c                                    :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/03/15 21:59:11 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/09/09 01:21:18 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 * @brief Checks if number has a sign
 * 
 * @param nb Number
 * @param elem Element
 * @return int 1 if sign, 0 if no sign
******************************************************************************/
static int	check_sign(intmax_t nb, t_pf_elem *elem)
{
	if (nb < 0)
		return (1);
	else
	{
		if (elem->is_plus || elem->is_space)
			return (1);
	}
	return (0);
}

/******************************************************************************
 * @brief Adds sign to buffer
 * 
 * @param nb Number
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
static int	add_sign(intmax_t nb, t_pf_elem *elem, t_pf_buffer *buffer)
{
	if (nb < 0)
	{
		if (pf_add_node(buffer, '-') == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		if (elem->is_plus)
		{
			if (pf_add_node(buffer, '+') == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (elem->is_space)
		{
			if (pf_add_node(buffer, ' ') == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
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
static int	handle_minus(intmax_t nb, char *base, t_pf_elem *elem, \
		t_pf_buffer *buffer)
{
	int	sign_len;

	sign_len = check_sign(nb, elem);
	if (add_sign(nb, elem, buffer) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (elem->is_dot)
	{
		if (pf_fill_width(buffer, elem->precision - \
				pf_len_signed(nb, base, elem), '0') == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	if (pf_add_signed_nb(nb, base, elem, buffer) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (pf_fill_width(buffer, elem->width - MAX(elem->precision + sign_len, \
			pf_len_signed(nb, base, elem) + sign_len), ' ') == EXIT_FAILURE)
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
static int	handle_default(intmax_t nb, char *base, t_pf_elem *elem, \
		t_pf_buffer *buffer)
{
	int	sign_len;

	sign_len = check_sign(nb, elem);
	if (elem->is_zero && !elem->is_dot)
	{
		if (add_sign(nb, elem, buffer) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (pf_fill_width(buffer, elem->width - (pf_len_signed(nb, base, \
							elem) + sign_len), '0') == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		if (pf_fill_width(buffer, elem->width - MAX(elem->precision + sign_len, \
				pf_len_signed(nb, base, elem) + sign_len), ' ') == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (add_sign(nb, elem, buffer) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	if (pf_fill_width(buffer, elem->precision - pf_len_signed(nb, base, elem), \
				'0') == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (pf_add_signed_nb(nb, base, elem, buffer) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Executes conversion for signed integer
 * 
 * @param nb Number
 * @param base Base
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
int	pf_handle_signed(intmax_t nb, char *base, t_pf_elem *elem, \
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
