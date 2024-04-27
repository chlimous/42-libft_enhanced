/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   parse_formatid.c                                   :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/02/21 01:55:23 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/04/27 01:56:18 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 * @brief Parses format specifier
 * 
 * @param ptr Format string pointer
 * @param elem Element pointer
 * @param args Arguments pointer
 * @return const char* Format string pointer after format specifier, or NULL in
	case of error
******************************************************************************/
const char	*parse_formatid(const char *ptr, t_elem *elem, va_list args)
{
	const t_handler	handler[] = {formatid_c, formatid_s, formatid_p, \
			formatid_di, formatid_di, formatid_u, formatid_x, \
			formatid_x, formatid_percent, formatid_fe, \
			formatid_fe, formatid_fe, formatid_fe, formatid_n, \
			formatid_o, formatid_k, 0};
	unsigned int	i;

	(void)args;
	i = 0;
	while (handler[i])
	{
		if (*ptr == SPECIFIERS[i])
		{
			elem->formatid = SPECIFIERS[i];
			elem->formatid_handler = handler[i];
			return (ptr + 1);
		}
		++i;
	}
	return (NULL);
}
