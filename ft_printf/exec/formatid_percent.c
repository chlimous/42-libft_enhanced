/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   formatid_percent.c                                 :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/02/28 17:16:40 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/03/17 17:14:53 by chlimous         ###   ########.fr       */
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
	if (elem->is_minus || elem->is_zero || elem->is_hash || elem->is_space \
			|| elem->is_plus || elem->is_dot || elem->width)
		return (EXIT_FAILURE);
	if (elem->length != NO_LEN)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Executes '%' conversion specifier and loads buffer
 * 
 * @param args Arguments pointer
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
int	formatid_percent(va_list args, t_elem *elem, t_buffer *buffer)
{
	(void)args;
	(void)elem;
	if (check_undefined(elem) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (add_node(buffer, '%') == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
