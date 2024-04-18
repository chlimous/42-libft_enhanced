/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   handle_unsigned2.c                                 :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/03/15 23:40:13 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/04/15 22:08:18 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "ft_printf.h"

/******************************************************************************
 * @brief Gets length of number
 * 
 * @param nb Number
 * @param base Base
 * @return int Length of number
******************************************************************************/
int	len_unsigned(uintmax_t nb, char *base, t_elem elem)
{
	int	len;

	if (nb == 0 && elem.is_dot && elem.precision == 0)
		return (0);
	len = 1;
	while (nb / ft_strlen(base) != 0)
	{
		nb /= ft_strlen(base);
		++len;
	}
	return (len);
}

/******************************************************************************
 * @brief Adds the number to the buffer
 * 
 * @param nb Number
 * @param base Base
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
int	add_unsigned_nb(uintmax_t nb, char *base, t_elem elem, t_buffer *buffer)
{
	if (nb == 0 && elem.is_dot && elem.precision == 0)
		return (EXIT_SUCCESS);
	if (nb / ft_strlen(base) != 0)
	{
		if (add_unsigned_nb(nb / ft_strlen(base), base, elem, buffer) \
				== EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	if (add_node(buffer, base[nb % ft_strlen(base)]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Checks prefix length
 * 
 * @param nb Number
 * @param elem Element
 * @return int Prefix length
******************************************************************************/
int	check_prefix_width(uintmax_t nb, t_elem elem)
{
	if (elem.is_hash && nb != 0)
	{
		if (elem.formatid == 'o')
			return (1);
		else if (elem.formatid == 'x' || elem.formatid == 'X')
			return (2);
	}
	return (0);
}

/******************************************************************************
 * @brief Checks prefix length for 'o' conversion, used in calculation of
	precision
 * 
 * @param nb Number
 * @param elem Element
 * @return int Prefix length
******************************************************************************/
int	check_prefix_precision(uintmax_t nb, t_elem elem)
{
	if (elem.is_hash && elem.formatid == 'o' && nb != 0)
		return (1);
	return (0);
}

/******************************************************************************
 * @brief Adds prefix to the buffer
 * 
 * @param nb Number
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
int	add_prefix(uintmax_t nb, t_elem elem, t_buffer *buffer)
{
	if (elem.formatid == 'p')
	{
		if (add_nodes(buffer, "0x") == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (elem.is_hash && nb != 0)
	{
		if (elem.formatid == 'x')
		{
			if (add_nodes(buffer, "0x") == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (elem.formatid == 'X')
		{
			if (add_nodes(buffer, "0X") == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (elem.formatid == 'o')
		{
			if (add_node(buffer, '0') == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
