/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/02/20 21:07:20 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/03/16 16:57:59 by chlimous         ###   ########.fr       */
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
const char	*parse_flags(const char *ptr, t_elem *elem, va_list args)
{
	const char *(*const	set_flag[FLAGS_QTY])(const char *, t_elem *) = \
	{set_minus, set_plus, set_space, set_hash, set_zero};
	int					i;

	(void)args;
	i = 0;
	while (i < FLAGS_QTY)
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
