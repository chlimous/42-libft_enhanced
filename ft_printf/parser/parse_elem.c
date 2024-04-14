/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   parse_elem.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/02/20 17:25:18 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/04/14 14:47:18 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 * @brief Parses conversion element
 * 
 * @param ptr Format string pointer
 * @param elem Element pointer
 * @param args Arguments pointer
 * @return const char* Format string pointer after conversion element
******************************************************************************/
const char	*parse_elem(const char *ptr, t_elem *elem, va_list args)
{
	const char *(*const	parsing[5])(const char *, t_elem *, va_list) = \
	{parse_flags, parse_width, parse_precision, parse_length, parse_formatid};
	unsigned int		i;

	ft_bzero(elem, sizeof(t_elem));
	i = 0;
	while (i < 5)
	{
		ptr = parsing[i](ptr, elem, args);
		if (!ptr)
			return (NULL);
		++i;
	}
	return (ptr);
}
