/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:34:31 by chlimous          #+#    #+#             */
/*   Updated: 2024/04/26 23:34:34 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 * @brief Manages argument length
 * 
 * @param args Arguments pointer
 * @param elem Element
 * @return intmax_t Argument integer
******************************************************************************/
long double	handle_length_float(va_list args, t_elem *elem)
{
	if (elem->length == L_UP_LEN)
		return (va_arg(args, long double));
	else
		return (va_arg(args, double));
}

/******************************************************************************
 * @brief Adds nan / inf to the buffer
 * 
 * @param nb Number
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
static int	add_nan_inf(long double nb, t_elem *elem, t_buffer *buffer)
{
	if (ft_isnan(nb) && (elem->formatid == 'f' || elem->formatid == 'e'))
	{
		if (add_nodes(buffer, NAN_LOW_MSG) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (ft_isnan(nb) && (elem->formatid == 'F' || elem->formatid == 'E'))
	{
		if (add_nodes(buffer, NAN_UP_MSG) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if ((nb == INFINITY || nb == -INFINITY) \
			&& (elem->formatid == 'f' || elem->formatid == 'e'))
	{
		if (add_nodes(buffer, INF_LOW_MSG) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if ((nb == INFINITY || nb == -INFINITY) \
			&& (elem->formatid == 'F' || elem->formatid == 'E'))
	{
		if (add_nodes(buffer, INF_UP_MSG) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

// Doesnt check for overflow: Don't use with INT_MIN
/******************************************************************************
 * @brief Returns absolute value of integer. Does not check for overflow, do
 	not use with INT_MIN
 * 
 * @param nb Number
 * @return int Absolute value
******************************************************************************/
int	abs_int(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

/******************************************************************************
 * @brief Gets length of number without sign
 * 
 * @param nb Number
 * @param elem Element
 * @return int Length of number
******************************************************************************/
int	len_float(long double nb, t_elem *elem)
{
	if (ft_isnan(nb) || nb == INFINITY || nb == -INFINITY)
		return (3);
	if (elem->formatid == 'f' || elem->formatid == 'F')
		return (len_float_f(nb, elem));
	else if (elem->formatid == 'e' || elem->formatid == 'E')
		return (len_float_e(nb, elem));
	return (0);
}

/******************************************************************************
 * @brief Adds the number to the buffer
 * 
 * @param nb Number
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
int	add_float_nb(long double nb, t_elem *elem, t_buffer *buffer)
{
	if (ft_isnan(nb) || nb == INFINITY || nb == -INFINITY)
	{
		if (add_nan_inf(nb, elem, buffer) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
		else
			return (EXIT_FAILURE);
	}
	if (elem->formatid == 'f' || elem->formatid == 'F')
	{
		if (add_float_f(nb, elem, buffer) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (elem->formatid == 'e' || elem->formatid == 'E')
	{
		if (add_float_e(nb, elem, buffer) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
