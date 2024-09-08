/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   formatid_o.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/03/10 13:52:06 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/04/13 12:48:21 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 * @brief Checks for undefined specifications
 * 
 * @param elem Element
 * @return int Exit status
******************************************************************************/
static int	check_undefined(t_pf_elem *elem)
{
	if (elem->is_space || elem->is_plus)
		return (EXIT_FAILURE);
	if (elem->length == L_UP_LEN)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Executes 'o' conversion specifier and loads buffer
 * 
 * @param args Arguments pointer
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
int	pf_formatid_o(va_list args, t_pf_elem *elem, t_pf_buffer *buffer)
{
	uintmax_t	nb;

	if (check_undefined(elem) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	nb = pf_handle_length_unsigned(args, elem);
	if (pf_handle_unsigned(nb, BASE_8, elem, buffer) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
