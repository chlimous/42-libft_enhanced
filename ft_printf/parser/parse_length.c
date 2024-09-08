/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/03/10 11:42:33 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/03/16 16:39:31 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 * @brief Checks if length in format string corresponds to parameter length
 * 
 * @param ptr Format string pointer
 * @param length Length string to compare
 * @return true ptr == length
 * @return false ptr != length
******************************************************************************/
static bool	is_length(const char *ptr, const char *length)
{
	unsigned int	i;

	i = 0;
	while (length[i] && ptr[i] == length[i])
	{
		++i;
		if (i == ft_strlen(length))
			return (true);
	}
	return (false);
}

/******************************************************************************
 * @brief Parses length
 * 
 * @param ptr Format string pointer
 * @param elem Element pointer
 * @param args Arguments pointer
 * @return const char* Format string pointer after length
******************************************************************************/
const char	*pf_parse_length(const char *ptr, t_pf_elem *elem, va_list args)
{
	const char		*length[] = {LENGTH_0, LENGTH_1, LENGTH_2, \
		LENGTH_3, LENGTH_4, LENGTH_5, LENGTH_6, LENGTH_7, LENGTH_8, 0};
	unsigned int	i;

	(void)args;
	i = 0;
	while (length[i])
	{
		if (is_length(ptr, length[i]))
		{
			elem->length = i;
			return (ptr + ft_strlen(length[i]));
		}
		++i;
	}
	return (ptr);
}
