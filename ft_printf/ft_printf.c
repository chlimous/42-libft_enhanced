/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/02/19 14:40:20 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/05/31 02:20:45 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "ft_printf.h"

/******************************************************************************
 * @brief Writes output to stdout
 * 
 * @param format Format string
 * @param ... Variable number of arguments
 * @return int Amount of printed characters or -1 in case of error
******************************************************************************/
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		buffer_size;

	va_start(args, format);
	buffer_size = ft_vdprintf(STDOUT_FILENO, format, args);
	va_end(args);
	return (buffer_size);
}

/******************************************************************************
 * @brief Writes output to file descriptor
 * 
 * @param fd Destination file descriptor
 * @param format Format string
 * @param args Arguments pointer
 * @return int Amount of printed characters or -1 in case of error
******************************************************************************/
int	ft_vdprintf(int fd, const char *format, va_list args)
{
	t_pf_buffer	buffer;

	if (!format)
		return (PRINTF_ERROR);
	if (pf_load_buffer(&buffer, format, args) == EXIT_FAILURE)
		return (PRINTF_ERROR);
	if (pf_flush(buffer, fd) == EXIT_FAILURE)
		return (PRINTF_ERROR);
	return (buffer.size);
}

/******************************************************************************
 * @brief Writes output to file descriptor
 * 
 * @param fd Destination file descriptor
 * @param format Format string
 * @param ... Variable number of arguments
 * @return int Amount of printed characters or -1 in case of error
******************************************************************************/
int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		buffer_size;

	va_start(args, format);
	buffer_size = ft_vdprintf(fd, format, args);
	va_end(args);
	return (buffer_size);
}

/******************************************************************************
 * @brief Writes output to stdout
 * 
 * @param format Format string
 * @param args Arguments pointer
 * @return int Amount of printed characters or -1 in case of error
******************************************************************************/
int	ft_vprintf(const char *format, va_list args)
{
	return (ft_vdprintf(STDOUT_FILENO, format, args));
}
