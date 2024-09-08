/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/02/20 21:07:20 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/04/18 20:28:12 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 * @brief Parses all flags
 * 
 * @param ptr Format string pointer
 * @param elem Element pointer
 * @param args Arguments pointer
 * @return const char* Format string pointer after flags
******************************************************************************/
const char	*pf_parse_flags(const char *ptr, t_pf_elem *elem, va_list args)
{
	const char *(*const	set_flag[])(const char *, t_pf_elem *) = \
	{pf_set_minus, pf_set_plus, pf_set_space, pf_set_hash, pf_set_zero, 0};
	int					i;

	(void)args;
	i = 0;
	while (set_flag[i])
	{
		if (*ptr == FLAGS[i])
		{
			ptr = set_flag[i](ptr, elem);
			if (!ptr)
				return (NULL);
			i = -1;
		}
		++i;
	}
	return (ptr);
}
