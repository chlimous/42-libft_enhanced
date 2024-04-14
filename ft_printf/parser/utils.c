/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/02/20 16:13:44 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/03/16 15:55:39 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 * @brief Parses and converts width/precision to integer
 * 
 * @param ptr Format string pointer
 * @param width Integer result
 * @param args Arguments pointer
 * @return const char* Format string pointer after width/precision or NULL in
	case of error
******************************************************************************/
const char	*process_width(const char *ptr, uintmax_t *width, va_list args)
{
	if (*ptr == '*')
	{
		*width = va_arg(args, int);
		return (ptr + 1);
	}
	*width = 0;
	while (ft_isdigit(*ptr))
	{
		*width = *width * 10 + (ft_ascii_to_nb(*ptr));
		if (*width > INT_MAX)
			return (NULL);
		++ptr;
	}
	return (ptr);
}
