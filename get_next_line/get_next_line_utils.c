/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:35:25 by chlimous          #+#    #+#             */
/*   Updated: 2024/05/01 20:40:07 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

bool	gnl_is_eol(t_gnl_node *node)
{
	ssize_t	i;

	if (!node)
		return (false);
	i = 0;
	while (i < node->size)
	{
		if (node->content[i] == '\n')
			return (true);
		++i;
	}
	return (false);
}

ssize_t	gnl_eol_index(t_gnl_node *node)
{
	ssize_t	i;

	i = 0;
	while (i < node->size)
	{
		if (node->content[i] == '\n')
			return (i);
		++i;
	}
	return (i - 1);
}

void	gnl_cpy(char *dest, const char *src, ssize_t size)
{
	ssize_t	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}
