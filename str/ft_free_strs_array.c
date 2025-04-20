/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_free_strs_array.c                               :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2025/04/20 19:50:40 by chlimous	       #+#    #+#	      */
/*   Updated: 2025/04/20 20:20:46 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

void	ft_free_strs_array(char ***array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		ft_free_strs(array[i]);
		++i;
	}
	free(array);
}
