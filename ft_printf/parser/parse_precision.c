/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/02/21 00:06:16 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/03/09 22:41:14 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static const char	*process_dot(const char *ptr, t_elem *elem)
{
	elem->is_dot = true;
	return (ptr + 1);
}

/******************************************************************************
 * @brief Parses precision
 * 
 * @param ptr Format string pointer
 * @param elem Element pointer
 * @param args Arguments pointer
 * @return const char* Format string pointer after precision
******************************************************************************/
const char	*parse_precision(const char *ptr, t_elem *elem, va_list args)
{
	uintmax_t	precision;

	if (*ptr == '.')
		ptr = process_dot(ptr, elem);
	ptr = process_width(ptr, &precision, args);
	if (!ptr)
		return (NULL);
	elem->precision = (int)precision;
	return (ptr);
}
