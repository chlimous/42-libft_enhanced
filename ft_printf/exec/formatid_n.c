/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   formatid_n.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/03/10 12:19:09 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/03/16 17:30:56 by chlimous         ###   ########.fr       */
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
	if (elem.is_minus || elem.is_zero || elem.is_hash || elem.is_space \
			|| elem.is_plus || elem.is_dot || elem.width)
		return (EXIT_FAILURE);
	if (elem.length != NO_LEN)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Executes 'n' conversion specifier
 * 
 * @param args Arguments pointer
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
int	formatid_n(va_list args, t_elem elem, t_buffer *buffer)
{
	int	*nb;

	(void)elem;
	if (check_undefined(elem) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	nb = va_arg(args, int *);
	*nb = buffer->size;
	return (EXIT_SUCCESS);
}
