/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:29:41 by chlimous          #+#    #+#             */
/*   Updated: 2024/03/08 20:30:51 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 * @brief Makes a new node
 * 
 * @param c Character that goes in the new node
 * @return t_node* New node
******************************************************************************/
t_node	*new_node(char c)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->c = c;
	new->next = NULL;
	return (new);
}
