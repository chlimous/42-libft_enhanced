/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/02/20 21:55:50 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/03/09 22:41:40 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "ft_printf.h"

/******************************************************************************
 * @brief Parses minimum field width
 * 
 * @param ptr Format string pointer
 * @param elem Element pointer
 * @param args Arguments pointer
 * @return const char* Format string pointer after width
******************************************************************************/
const char	*pf_parse_width(const char *ptr, t_pf_elem *elem, va_list args)
{
	uintmax_t	width;

	(void)elem;
	ptr = pf_process_width(ptr, &width, args);
	if (!ptr)
		return (NULL);
	elem->width = (int)width;
	return (ptr);
}
