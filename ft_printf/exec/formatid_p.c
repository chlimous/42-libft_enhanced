/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   formatid_p.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/02/28 17:16:40 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/04/15 21:55:40 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 * @brief Executes conversion for '-' flag
 * 
 * @param adr Pointer address
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
static int	handle_minus(uintptr_t adr, t_elem *elem, t_buffer *buffer)
{
	if (adr)
	{
		if (add_nodes(buffer, "0x") == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (add_unsigned_nb(adr, BASE_16_LOW, elem, buffer) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (fill_width(buffer, elem->width - (len_unsigned(adr, \
					BASE_16_LOW, elem) + 2), ' ') == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		if (add_nodes(buffer, NIL_MSG) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (fill_width(buffer, elem->width - \
					ft_strlen(NIL_MSG), ' ') == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Executes conversion
 * 
 * @param adr Pointer address
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
static int	handle_default(uintptr_t adr, t_elem *elem, t_buffer *buffer)
{
	if (adr)
	{
		if (fill_width(buffer, elem->width - (len_unsigned(adr, \
					BASE_16_LOW, elem) + 2), ' ') == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (add_nodes(buffer, "0x") == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (add_unsigned_nb(adr, BASE_16_LOW, elem, buffer) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		if (fill_width(buffer, elem->width - \
				ft_strlen(NIL_MSG), ' ') == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (add_nodes(buffer, NIL_MSG) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
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
	if (elem->length != NO_LEN)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Executes 'p' conversion specifier and loads buffer
 * 
 * @param args Arguments pointer
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
int	formatid_p(va_list args, t_elem *elem, t_buffer *buffer)
{
	uintptr_t	adr;

	if (check_undefined(elem) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	adr = (uintptr_t)va_arg(args, void *);
	if (elem->is_minus)
	{
		if (handle_minus(adr, elem, buffer) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		if (handle_default(adr, elem, buffer) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
