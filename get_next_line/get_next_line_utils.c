/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:35:25 by chlimous          #+#    #+#             */
/*   Updated: 2024/09/15 03:33:08 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_eol(t_node *node)
{
	ssize_t	i;

	if (!node)
		return (0);
	i = 0;
	while (i < node->size)
	{
		if (node->content[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

ssize_t	get_eol_index(t_node *node)
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

void	cpy(char *dest, const char *src, ssize_t size)
{
	ssize_t	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		++i;
	}
}
