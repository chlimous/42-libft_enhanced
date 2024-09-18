/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/05/31 02:21:13 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/09/07 01:11:12 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "ft_printf.h"

/******************************************************************************
 * @brief Allocates memory and writes to string
 * 
 * @param str Output string
 * @param format Format string
 * @param ... Variable number of arguments
 * @return int Amount of characters written or -1 in case of error
******************************************************************************/
int	ft_asprintf(char **str, const char *format, ...)
{
	va_list	args;
	int		buffer_size;

	va_start(args, format);
	buffer_size = ft_vasprintf(str, format, args);
	va_end(args);
	return (buffer_size);
}

/******************************************************************************
 * @brief Allocates memory and writes to string
 * 
 * @param str Output string
 * @param format Format string
 * @param args Arguments pointer
 * @return int Amount of characters written or -1 in case of error
******************************************************************************/
int	ft_vasprintf(char **str, const char *format, va_list args)
{
	t_pf_buffer	buffer;

	if (!format)
		return (PRINTF_ERROR);
	if (pf_load_buffer(&buffer, format, args) == EXIT_FAILURE)
		return (PRINTF_ERROR);
	*str = malloc(sizeof(char) * (buffer.size + 1));
	if (!str)
		return (pf_clear_buffer(buffer), PRINTF_ERROR);
	pf_buffer_to_string(*str, (size_t)INT_MAX + 1, buffer);
	return (buffer.size);
}
