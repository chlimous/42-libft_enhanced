/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/03/06 22:07:28 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/03/15 23:28:27 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

const char	*pf_set_minus(const char *ptr, t_pf_elem *elem)
{
	if (elem->is_minus)
		return (NULL);
	elem->is_minus = true;
	return (ptr + 1);
}

const char	*pf_set_plus(const char *ptr, t_pf_elem *elem)
{
	if (elem->is_plus)
		return (NULL);
	elem->is_plus = true;
	return (ptr + 1);
}

const char	*pf_set_space(const char *ptr, t_pf_elem *elem)
{
	if (elem->is_space)
		return (NULL);
	elem->is_space = true;
	return (ptr + 1);
}

const char	*pf_set_hash(const char *ptr, t_pf_elem *elem)
{
	if (elem->is_hash)
		return (NULL);
	elem->is_hash = true;
	return (ptr + 1);
}

const char	*pf_set_zero(const char *ptr, t_pf_elem *elem)
{
	if (elem->is_zero)
		return (NULL);
	elem->is_zero = true;
	return (ptr + 1);
}
