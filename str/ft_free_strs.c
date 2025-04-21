/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_free_strs.c                                     :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2025/04/20 19:50:07 by chlimous	       #+#    #+#	      */
/*   Updated: 2025/04/21 17:50:53 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	ft_free_strs(char **strs)
{
	size_t	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		++i;
	}
	free(strs);
}
