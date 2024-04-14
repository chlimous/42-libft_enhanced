/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   formatid_x.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/02/28 17:16:40 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/03/16 17:32:34 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 * @brief Gets lowercase or uppercase base
 * 
 * @param elem Element
 * @return char* Base
******************************************************************************/
static char	*get_base(t_elem elem)
{
	if (elem.formatid == 'x')
		return (BASE_16_LOW);
	else if (elem.formatid == 'X')
		return (BASE_16_UP);
	return (NULL);
}

/******************************************************************************
 * @brief Checks for undefined specifications
 * 
 * @param elem Element
 * @return int Exit status
******************************************************************************/
static int	check_undefined(t_elem elem)
{
	if (elem.is_space || elem.is_plus)
		return (EXIT_FAILURE);
	if (elem.length == L_UP_LEN)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Executes 'x' / 'X' conversion specifiers and loads buffer
 * 
 * @param args Arguments pointer
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
int	formatid_x(va_list args, t_elem elem, t_buffer *buffer)
{
	uintmax_t	nb;

	if (check_undefined(elem) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	nb = handle_length_unsigned(args, elem);
	if (handle_unsigned(nb, get_base(elem), elem, buffer) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
