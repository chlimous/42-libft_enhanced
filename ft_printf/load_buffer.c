/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   load_buffer.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/05/31 02:19:51 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/05/31 02:20:05 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 * @brief Parses format string and arguments and loads the buffer
 * 
 * @param buffer Buffer pointer
 * @param format Format string
 * @param args Arguments pointer
 * @return int Exit status
******************************************************************************/
int	pf_load_buffer(t_pf_buffer *buffer, const char *format, va_list args)
{
	t_pf_elem		elem;

	ft_bzero(buffer, sizeof(t_pf_buffer));
	while (*format)
	{
		if (*format == '%')
		{
			format = pf_parse_elem(format + 1, &elem, args);
			if (!format)
				return (pf_clear_buffer(*buffer), EXIT_FAILURE);
			if (elem.formatid_handler(args, &elem, buffer) == EXIT_FAILURE)
				return (pf_clear_buffer(*buffer), EXIT_FAILURE);
		}
		else
		{
			if (pf_add_node(buffer, *format) == EXIT_FAILURE)
				return (pf_clear_buffer(*buffer), EXIT_FAILURE);
			++format;
		}
	}
	return (EXIT_SUCCESS);
}
