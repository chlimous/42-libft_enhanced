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

#include "ft_printf.h"

/******************************************************************************
 * @brief Makes a new node
 * 
 * @param c Character that goes in the new node
 * @return t_pf_node* New node
******************************************************************************/
t_pf_node	*pf_new_node(char c)
{
	t_pf_node	*new;

	new = malloc(sizeof(t_pf_node));
	if (!new)
		return (NULL);
	new->c = c;
	new->next = NULL;
	return (new);
}
