/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/04/13 18:54:05 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/05/31 02:21:56 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "ft_printf.h"

/******************************************************************************
 * @brief Writes output to string
 * 
 * @param str Output string
 * @param format Format string
 * @param ... Variable number of arguments
 * @return int Amount of characters written or -1 in case of error
******************************************************************************/
int	ft_sprintf(char *str, const char *format, ...)
{
	va_list	args;
	int		buffer_size;

	va_start(args, format);
	buffer_size = ft_vsnprintf(str, (size_t)INT_MAX + 1, format, args);
	va_end(args);
	return (buffer_size);
}

/******************************************************************************
 * @brief Writes output to string
 * 
 * @param str Output string
 * @param size Maximum number of bytes to add to the string, '\0' included
 * @param format Format string
 * @param ... Variable number of arguments
 * @return int Amount of bytes that could have been written to the string,
		or -1 in case of error
******************************************************************************/
int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list	args;
	int		buffer_size;

	va_start(args, format);
	buffer_size = ft_vsnprintf(str, size, format, args);
	va_end(args);
	return (buffer_size);
}

/******************************************************************************
 * @brief Writes output to string
 * 
 * @param str Output string
 * @param format Format string
 * @param args Arguments pointer
 * @return int Amount of characters written or -1 in case of error
******************************************************************************/
int	ft_vsprintf(char *str, const char *format, va_list args)
{
	return (ft_vsnprintf(str, (size_t)INT_MAX + 1, format, args));
}

/******************************************************************************
 * @brief Writes output to string
 * 
 * @param str Output string
 * @param size Maximum number of bytes to add to the string, '\0' included
 * @param format Format string
 * @param args Arguments pointer
 * @return int Amount of bytes that could have been written to the string,
		or -1 in case of error
******************************************************************************/
int	ft_vsnprintf(char *str, size_t size, const char *format, va_list args)
{
	t_pf_buffer	buffer;

	if (!format)
		return (PRINTF_ERROR);
	if (pf_load_buffer(&buffer, format, args) == EXIT_FAILURE)
		return (PRINTF_ERROR);
	pf_buffer_to_string(str, size, buffer);
	return (buffer.size);
}
