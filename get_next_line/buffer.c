/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:35:21 by chlimous          #+#    #+#             */
/*   Updated: 2024/05/01 20:39:59 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl_node	*new_node(char *content)
{
	t_gnl_node	*new;

	new = malloc(sizeof(t_gnl_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

static void	add_back(t_gnl_buffer *buffer, t_gnl_node *new)
{
	if (buffer->tail)
	{
		buffer->tail->next = new;
		buffer->tail = new;
		++buffer->size;
	}
	else
	{
		buffer->head = new;
		buffer->tail = new;
		++buffer->size;
	}
}

void	gnl_clear_buffer(t_gnl_buffer *buffer)
{
	t_gnl_node	*next;

	while (buffer->head)
	{
		next = buffer->head->next;
		free(buffer->head->content);
		free(buffer->head);
		buffer->head = next;
	}
	buffer->tail = NULL;
	buffer->size = 0;
}

void	gnl_partial_clear_buffer(t_gnl_buffer *buffer)
{
	t_gnl_node	*next;

	while (buffer->head->next)
	{
		next = buffer->head->next;
		free(buffer->head->content);
		free(buffer->head);
		buffer->head = next;
	}
	buffer->head = buffer->tail;
	buffer->size = 1;
}

int	gnl_add_node(t_gnl_buffer *buffer, char *content)
{
	t_gnl_node	*new;

	new = new_node(content);
	if (!new)
		return (EXIT_FAILURE);
	add_back(buffer, new);
	return (EXIT_SUCCESS);
}
