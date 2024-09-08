/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   parse_elem.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/02/20 17:25:18 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/09/08 19:57:14 by chlimous         ###   ########.fr       */
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
const char	*pf_parse_elem(const char *ptr, t_pf_elem *elem, va_list args)
{
	const char *(*const	parsing[5])(const char *, t_pf_elem *, va_list) = \
	{pf_parse_flags, pf_parse_width, pf_parse_precision, pf_parse_length, \
		pf_parse_formatid};
	unsigned int		i;

	ft_bzero(elem, sizeof(t_pf_elem));
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
