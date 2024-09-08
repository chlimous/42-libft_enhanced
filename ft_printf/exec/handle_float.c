/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:34:19 by chlimous          #+#    #+#             */
/*   Updated: 2024/04/26 23:34:21 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 * @brief Checks if number has a sign
 * 
 * @param nb Number
 * @param elem Element
 * @return int 1 if sign, 0 if no sign
******************************************************************************/
int	pf_check_sign_float(long double nb, t_pf_elem *elem)
{
	if (ft_isnan(nb) || nb == INFINITY)
		return (0);
	if (nb == -INFINITY)
		return (1);
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
static int	add_sign(long double nb, t_pf_elem *elem, t_pf_buffer *buffer)
{
	if (ft_isnan(nb) || nb == INFINITY)
		return (EXIT_SUCCESS);
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
static int	handle_minus(long double nb, t_pf_elem *elem, t_pf_buffer *buffer)
{
	int	sign_len;

	sign_len = pf_check_sign_float(nb, elem);
	if (add_sign(nb, elem, buffer) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (pf_add_float_nb(nb, elem, buffer) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (pf_fill_width(buffer, elem->width - (pf_len_float(nb, elem) \
					+ sign_len), ' ') == EXIT_FAILURE)
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
static int	handle_default(long double nb, t_pf_elem *elem, t_pf_buffer *buffer)
{
	int	sign_len;

	sign_len = pf_check_sign_float(nb, elem);
	if (elem->is_zero)
	{
		if (add_sign(nb, elem, buffer) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (pf_fill_width(buffer, elem->width - (pf_len_float(nb, elem) \
						+ sign_len), '0') == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		if (pf_fill_width(buffer, elem->width - (pf_len_float(nb, elem) \
						+ sign_len), ' ') == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (add_sign(nb, elem, buffer) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	if (pf_add_float_nb(nb, elem, buffer) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Executes conversion for floating point number
 * 
 * @param nb Number
 * @param base Base
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
int	pf_handle_float(long double nb, t_pf_elem *elem, t_pf_buffer *buffer)
{
	if (pf_len_float(nb, elem) == -1)
		return (EXIT_FAILURE);
	if (elem->is_minus)
	{
		if (handle_minus(nb, elem, buffer) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		if (handle_default(nb, elem, buffer) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
