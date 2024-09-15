/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/07 00:39:43 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/09/15 04:53:17 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

char	*ft_strdup(const char *src)
{
	return(ft_strndup(src, SIZE_MAX));
}
