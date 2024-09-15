/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:13:55 by chlimous          #+#    #+#             */
/*   Updated: 2024/03/08 20:14:17 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/******************************************************************************
 * @brief Frees the buffer
 * 
 * @param buffer Buffer
******************************************************************************/
void	clear_buffer(t_buffer buffer)
{
	t_node	*current;
	t_node	*tmp;

	current = buffer.head;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}
