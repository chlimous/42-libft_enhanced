/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   formatid_n.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/03/10 12:19:09 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/04/28 00:42:38 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 * @brief Checks for undefined specifications
 * 
 * @param elem Element
 * @return int Exit status
******************************************************************************/
static int	check_undefined(t_pf_elem *elem)
{
	if (elem->is_minus || elem->is_zero || elem->is_hash || elem->is_space \
			|| elem->is_plus || elem->is_dot || elem->width)
		return (EXIT_FAILURE);
	if (elem->length == L_UP_LEN)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Executes 'n' conversion specifier
 * 
 * @param args Arguments pointer
 * @param elem Element
 * @param buffer Buffer pointer
 * @return int Exit status
******************************************************************************/
int	pf_formatid_k(va_list args, t_pf_elem *elem, t_pf_buffer *buffer)
{
	if (check_undefined(elem) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (elem->length == NO_LEN)
		*(va_arg(args, int *)) = (int)buffer->size;
	else if (elem->length == HH_LOW_LEN)
		*(va_arg(args, signed char *)) = (signed char)buffer->size;
	else if (elem->length == H_LOW_LEN)
		*(va_arg(args, short int *)) = (short int)buffer->size;
	else if (elem->length == L_LOW_LEN)
		*(va_arg(args, long int *)) = (long int)buffer->size;
	else if (elem->length == LL_LOW_LEN)
		*(va_arg(args, long long int *)) = (long long int)buffer->size;
	else if (elem->length == J_LOW_LEN)
		*(va_arg(args, intmax_t *)) = (intmax_t)buffer->size;
	else if (elem->length == Z_LOW_LEN)
		*(va_arg(args, size_t *)) = (size_t)buffer->size;
	else if (elem->length == T_LOW_LEN)
		*(va_arg(args, ptrdiff_t *)) = (ptrdiff_t)buffer->size;
	return (EXIT_SUCCESS);
}
