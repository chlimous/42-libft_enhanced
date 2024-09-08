/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:35:04 by chlimous          #+#    #+#             */
/*   Updated: 2024/04/28 00:22:32 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 * @brief Get the exponent and normalize the number to scientific notation
 * 
 * @param nb Number pointer
 * @return int Exponent
******************************************************************************/
static int	get_exponent(long double *nb)
{
	int	exp;

	if (*nb == 0.0)
		return (0);
	exp = 0;
	while (*nb <= -10.0 || *nb >= 10.0)
	{
		++exp;
		*nb /= 10;
	}
	while ((*nb < 0.0 && *nb > -1.0) || (*nb > 0.0 && *nb < 1.0))
	{
		--exp;
		*nb *= 10;
	}
	return (exp);
}

/******************************************************************************
 * @brief Adds exponent digits to the buffer
 * 
 * @param exp Exponent
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
static int	add_exponent_digits(int exp, t_pf_buffer *buffer)
{
	if (exp / 10 != 0)
	{
		if (add_exponent_digits(exp / 10, buffer) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	if (pf_add_node(buffer, BASE_10[pf_abs_int(exp) % 10]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Adds the exponent part to the buffer
 * 
 * @param exp Exponent
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
static int	add_exponent_part(int exp, t_pf_elem *elem, t_pf_buffer *buffer)
{
	if (elem->formatid == 'e')
	{
		if (pf_add_node(buffer, 'e') == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (elem->formatid == 'E')
	{
		if (pf_add_node(buffer, 'E') == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	if (exp < 0)
	{
		if (pf_add_node(buffer, '-') == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
		if (pf_add_node(buffer, '+') == EXIT_FAILURE)
			return (EXIT_FAILURE);
	if ((exp < 0 && exp > -10) || (exp >= 0 && exp < 10))
		if (pf_add_node(buffer, '0') == EXIT_FAILURE)
			return (EXIT_FAILURE);
	if (add_exponent_digits(exp, buffer) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Adds the number to the buffer with %e / %E specifiers
 * 
 * @param nb Number
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
int	pf_add_float_e(long double nb, t_pf_elem *elem, t_pf_buffer *buffer)
{
	int	exp;

	exp = get_exponent(&nb);
	if (pf_add_node(buffer, BASE_10[pf_abs_int((int)nb)]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	nb -= (int)nb;
	if (!(elem->is_dot && elem->precision == 0 && !elem->is_hash))
	{
		if (pf_add_node(buffer, '.') == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (pf_add_float_dec(nb, elem, buffer) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	if (add_exponent_part(exp, elem, buffer) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
