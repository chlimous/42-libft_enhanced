/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   parse_formatid.c                                   :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/02/21 01:55:23 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/03/16 16:58:15 by chlimous         ###   ########.fr       */
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
	const t_handler	handler[SPECIFIERS_QTY] = {formatid_c, formatid_s, \
		formatid_p, formatid_d, formatid_d, formatid_u, formatid_x, \
			formatid_x, formatid_percent, formatid_n, \
			formatid_o, formatid_k};
	unsigned int	i;

	(void)args;
	i = 0;
	while (i < SPECIFIERS_QTY)
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
