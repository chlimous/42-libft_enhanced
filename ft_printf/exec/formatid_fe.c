/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   formatid_fe.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/04/26 23:35:26 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/04/26 23:40:09 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 * @brief Checks for undefined specifications
 *
 * @param elem Element
 * @return int Exit status
******************************************************************************/
static int	check_undefined(t_elem *elem)
{
	if (elem->length != NO_LEN && elem->length != L_UP_LEN)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Executes 'f' and 'e' conversion specifiers and loads buffer
 * 
 * @param args Arguments pointer
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
int	formatid_fe(va_list args, t_elem *elem, t_buffer *buffer)
{
	long double	nb;

	if (check_undefined(elem) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	nb = handle_length_float(args, elem);
	if (handle_float(nb, elem, buffer) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
