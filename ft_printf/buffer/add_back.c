/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/03/01 21:35:31 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/04/14 10:40:50 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 * @brief Adds node at the end of the buffer
 * 
 * @param buffer Buffer pointer
 * @param new New node
******************************************************************************/
void	pf_add_back(t_pf_buffer *buffer, t_pf_node *new)
{
	if (buffer->size)
	{
		buffer->tail->next = new;
		buffer->tail = new;
		++(buffer->size);
	}
	else
	{
		buffer->head = new;
		buffer->tail = new;
		++(buffer->size);
	}
}
