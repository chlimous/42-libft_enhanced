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

#include "ft_printf.h"

/******************************************************************************
 * @brief Parses format specifier
 * 
 * @param ptr Format string pointer
 * @param elem Element pointer
 * @param args Arguments pointer
 * @return const char* Format string pointer after format specifier, or NULL in
	case of error
******************************************************************************/
const char	*pf_parse_formatid(const char *ptr, t_pf_elem *elem, va_list args)
{
	const t_handler	handler[] = {pf_formatid_c, pf_formatid_s, pf_formatid_p, \
			pf_formatid_di, pf_formatid_di, pf_formatid_u, pf_formatid_x, \
			pf_formatid_x, pf_formatid_percent, pf_formatid_fe, \
			pf_formatid_fe, pf_formatid_fe, pf_formatid_fe, pf_formatid_k, \
			pf_formatid_o, pf_formatid_k, 0};
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
