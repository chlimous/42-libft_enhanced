/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   buffer_to_string.c                                 :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/03/04 17:19:07 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/09/18 02:26:46 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "ft_printf.h"

/******************************************************************************
 * @brief Converts the buffer to a string
 * 
 * @param str Final string
 * @param size Maximum number of bytes to add to the string, '\0' included
 * @param buffer Buffer
******************************************************************************/
void	pf_buffer_to_string(char *str, size_t size, t_pf_buffer buffer)
{
	t_pf_node	*current;
	size_t		i;

	current = buffer.head;
	i = 0;
	while (current && size != 0 && i < size - 1)
	{
		str[i] = current->c;
		++i;
		current = current->next;
	}
	if (size > 0)
		str[i] = '\0';
	pf_clear_buffer(buffer);
}
