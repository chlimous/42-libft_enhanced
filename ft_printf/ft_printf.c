/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/02/19 14:40:20 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/04/27 01:53:47 by chlimous         ###   ########.fr       */
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
int	ft_print(t_buffer *buffer, const char *format, va_list args)
{
	t_elem		elem;

	ft_bzero(buffer, sizeof(t_buffer));
	while (*format)
	{
		if (*format == '%')
		{
			format = parse_elem(format + 1, &elem, args);
			if (!format)
				return (clear_buffer(*buffer), EXIT_FAILURE);
			if (elem.formatid_handler(args, &elem, buffer) == EXIT_FAILURE)
				return (clear_buffer(*buffer), EXIT_FAILURE);
		}
		else
		{
			if (add_node(buffer, *format) == EXIT_FAILURE)
				return (clear_buffer(*buffer), EXIT_FAILURE);
			++format;
		}
	}
	return (EXIT_SUCCESS);
}

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
	t_buffer	buffer;

	if (!format)
		return (PRINT_ERROR);
	if (ft_print(&buffer, format, args) == EXIT_FAILURE)
		return (PRINT_ERROR);
	if (flush(buffer, fd) == EXIT_FAILURE)
		return (PRINT_ERROR);
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
