/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   formatid_c.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/02/28 17:16:40 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/03/16 17:32:58 by chlimous         ###   ########.fr       */
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
static intmax_t	handle_length(va_list args, t_elem *elem)
{
	if (elem->length == L_LOW_LEN)
		return (va_arg(args, wint_t));
	else
		return (va_arg(args, int));
}

/******************************************************************************
 * @brief Checks for undefined specifications
 * 
 * @param elem Element
 * @return int Exit status
******************************************************************************/
static int	check_undefined(t_elem *elem)
{
	if (elem->is_zero || elem->is_hash || elem->is_space || elem->is_plus \
			|| elem->is_dot)
		return (EXIT_FAILURE);
	if (elem->length != NO_LEN && elem->length != L_LOW_LEN)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Executes 'c' conversion specifier and loads buffer
 * 
 * @param args Arguments pointer
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
int	formatid_c(va_list args, t_elem *elem, t_buffer *buffer)
{
	intmax_t	c;

	if (check_undefined(elem) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	c = handle_length(args, elem);
	if (elem->is_minus)
	{
		if (add_node(buffer, c) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (fill_width(buffer, elem->width - 1, ' ') == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		if (fill_width(buffer, elem->width - 1, ' ') == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (add_node(buffer, c) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
