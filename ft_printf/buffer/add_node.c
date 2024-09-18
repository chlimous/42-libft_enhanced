/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:33:29 by chlimous          #+#    #+#             */
/*   Updated: 2024/03/10 17:50:16 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/******************************************************************************
 * @brief Makes a new node and adds it to the buffer
 * 
 * @param buffer Buffer pointer
 * @param c Character that goes in the new node
 * @return int Exit status
******************************************************************************/
int	pf_add_node(t_pf_buffer *buffer, char c)
{
	t_pf_node	*new;

	if (buffer->size == INT_MAX)
		return (EXIT_FAILURE);
	new = pf_new_node(c);
	if (!new)
		return (EXIT_FAILURE);
	pf_add_back(buffer, new);
	return (EXIT_SUCCESS);
}

/******************************************************************************
 * @brief Adds a string to the buffer, one char at a time
 * 
 * @param buffer Buffer pointer
 * @param str String to add
 * @return int Exit status
******************************************************************************/
int	pf_add_nodes(t_pf_buffer *buffer, char *str)
{
	while (*str)
	{
		if (pf_add_node(buffer, *str) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		++str;
	}
	return (EXIT_SUCCESS);
}
