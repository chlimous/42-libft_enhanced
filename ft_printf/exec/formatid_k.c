/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   formatid_k.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/02/28 17:16:40 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/09/04 18:47:39 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 * @brief Checks if base is correct: more than 2 characters, no duplicate, no
	whitespace, only printable characters
 * 
 * @param base Base
 * @return char* Base or NULL in case of error
******************************************************************************/
static char	*check_base(char *base)
{
	unsigned int	i;

	if (!base || ft_strlen(base) < 2)
		return (NULL);
	i = 0;
	while (base[i])
	{
		if (ft_isspace(base[i]))
			return (NULL);
		if (!ft_isprint(base[i]))
			return (NULL);
		if (ft_strchr(base + i + 1, base[i]))
			return (NULL);
		++i;
	}
	return (base);
}

/******************************************************************************
 * @brief Checks for undefined specifications
 * 
 * @param elem Element
 * @return int Exit status
******************************************************************************/
static int	check_undefined(t_pf_elem *elem)
{
	if (elem->is_hash || elem->is_space || elem->is_plus)
		return (EXIT_FAILURE);
	if (elem->length == L_UP_LEN)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Executes 'k' conversion specifier and loads buffer
 * 
 * @param args Arguments pointer
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
int	pf_formatid_k(va_list args, t_pf_elem *elem, t_pf_buffer *buffer)
{
	uintmax_t		nb;
	char			*base;

	if (check_undefined(elem) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	nb = pf_handle_length_unsigned(args, elem);
	base = check_base(va_arg(args, char *));
	if (!base)
		return (EXIT_FAILURE);
	if (base[0] != '0')
		elem->precision = 0;
	if (pf_handle_unsigned(nb, base, elem, buffer) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
