/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/03/07 04:06:52 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/03/17 17:45:11 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 * @brief Fill buffer with specific characters, for width/precision management
 * 
 * @param buffer Buffer pointer
 * @param amount Amount to fill
 * @param filler Character used as filler
 * @return int Exit status
******************************************************************************/
int	fill_width(t_buffer *buffer, int amount, char filler)
{
	while (amount > 0)
	{
		if (add_node(buffer, filler) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		--amount;
	}
	return (EXIT_SUCCESS);
}
