/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   formatid_d.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/02/28 17:16:40 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/03/16 17:30:37 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 * @brief Checks for undefined specifications
 * 
 * @param elem Element
 * @return int Exit status
******************************************************************************/
static int	check_undefined(t_elem elem)
{
	if (elem.is_hash)
		return (EXIT_FAILURE);
	if (elem.length == L_UP_LEN)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Executes 'd' / 'i' conversion specifiers and loads buffer
 * 
 * @param args Arguments pointer
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
int	formatid_d(va_list args, t_elem elem, t_buffer *buffer)
{
	intmax_t	nb;

	if (check_undefined(elem) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	nb = handle_length_signed(args, elem);
	if (handle_signed(nb, BASE_10, elem, buffer) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
