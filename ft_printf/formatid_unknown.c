/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   formatid_unknown.c                                 :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/22 04:59:27 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/12/31 04:36:16 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

size_t	formatid_unknown(char identifier)
{
	ft_putchar_fd('%', 1);
	ft_putchar_fd(identifier, 1);
	return (2);
}
