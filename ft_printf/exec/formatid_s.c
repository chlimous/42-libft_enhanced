/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   formatid_s.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/02/28 17:16:40 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/03/16 17:48:31 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "ft_printf.h"

/******************************************************************************
 * @brief Gets the number of characters of the string to add
 * 
 * @param elem Element
 * @param str String to add
 * @return int Number of characters to add
******************************************************************************/
static int	char_to_add(t_elem *elem, char *str)
{
	int		add_size;
	size_t	len;

	len = ft_strlen(str);
	if (elem->is_dot && (int)len >= elem->precision)
		add_size = elem->precision;
	else
		add_size = len;
	return (add_size);
}

/******************************************************************************
 * @brief Adds string to buffer
 * 
 * @param elem Element
 * @param buffer Buffer pointer
 * @param str String to add
 * @return int Exit status
******************************************************************************/
static int	add_string(t_elem *elem, t_buffer *buffer, char *str)
{
	int	add_size;
	int	i;

	add_size = char_to_add(elem, str);
	i = 0;
	while (str[i] && i < add_size)
	{
		if (add_node(buffer, str[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		++i;
	}
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Gets string from va_list
 * 
 * @param args Arguments pointer
 * @param str Argument string pointer
 * @return int Exit status
******************************************************************************/
static int	get_arg(va_list args, char **str)
{
	*str = va_arg(args, char *);
	if (!*str)
		*str = NULL_MSG;
	if (ft_strlen(*str) > INT_MAX)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Checks for undefined specifications
 * 
 * @param elem Element
 * @return int Exit status
******************************************************************************/
static int	check_undefined(t_elem *elem)
{
	if (elem->is_zero || elem->is_hash || elem->is_space || elem->is_plus)
		return (EXIT_FAILURE);
	if (elem->length != NO_LEN)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Executes 's' conversion specifier and loads buffer
 * 
 * @param args Arguments pointer
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
int	formatid_s(va_list args, t_elem *elem, t_buffer *buffer)
{
	char	*str;
	int		add_size;

	if (check_undefined(elem) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (get_arg(args, &str) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	add_size = char_to_add(elem, str);
	if (elem->is_minus)
	{
		if (add_string(elem, buffer, str) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (fill_width(buffer, elem->width - add_size, ' ') == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		if (fill_width(buffer, elem->width - add_size, ' ') == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (add_string(elem, buffer, str) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
