/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:35:18 by chlimous          #+#    #+#             */
/*   Updated: 2025/04/09 10:05:28 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	trim_buffer(t_gnl_buffer *buffer, ssize_t eol_index)
{
	char	*content;
	ssize_t	len;

	gnl_partial_clear_buffer(buffer);
	len = buffer->head->size - eol_index - 1;
	if (len > 0)
	{
		content = malloc(sizeof(char) * len);
		if (!content)
			return (EXIT_FAILURE);
		gnl_cpy(content, buffer->head->content + eol_index + 1, len);
		free(buffer->head->content);
		buffer->head->content = content;
		buffer->head->size = len;
	}
	else
		gnl_clear_buffer(buffer);
	return (EXIT_SUCCESS);
}

static size_t	line_len(t_gnl_buffer *buffer, ssize_t eol_index)
{
	size_t	size;

	size = eol_index + 1;
	if (buffer->size >= 2)
		size += buffer->head->size;
	if (buffer->size > 2)
		size += (buffer->size - 2) * GNL_BUFFER_SIZE;
	return (size);
}

static void	buffer_to_string(t_gnl_buffer buffer, char *line, \
		ssize_t eol_index)
{
	size_t		node_i;
	size_t		line_i;

	line_i = 0;
	node_i = 0;
	while (buffer.head)
	{
		if (node_i == buffer.size - 1)
		{
			gnl_cpy(line + line_i, buffer.head->content, eol_index + 1);
			line[line_i + (eol_index + 1)] = '\0';
		}
		else if (node_i == 0)
		{
			gnl_cpy(line, buffer.head->content, buffer.head->size);
			line_i += buffer.head->size;
		}
		else
		{
			gnl_cpy(line + line_i, buffer.head->content, GNL_BUFFER_SIZE);
			line_i += GNL_BUFFER_SIZE;
		}
		++node_i;
		buffer.head = buffer.head->next;
	}
}

static size_t	get_line(t_gnl_buffer *buffer, char **line)
{
	size_t	len;
	ssize_t	eol_index;

	if (buffer->size == 0)
		return (0);
	eol_index = gnl_eol_index(buffer->tail);
	len = line_len(buffer, eol_index);
	*line = malloc(sizeof(char) * (len + 1));
	if (!*line)
		return (gnl_clear_buffer(buffer), -1);
	buffer_to_string(*buffer, *line, eol_index);
	if (trim_buffer(buffer, eol_index) == EXIT_FAILURE)
		return (free(*line), gnl_clear_buffer(buffer), -1);
	return (len);
}

size_t	get_next_line(int fd, char **line, int flag)
{
	static t_gnl_buffer	buffer[GNL_FD_MAX + 1];
	ssize_t				bytesread;
	char				*content;

	if (flag == GNL_FLUSH)
		return (gnl_clear_buffer(&buffer[fd]), 0);
	bytesread = 1;
	while (bytesread > 0 && !gnl_is_eol(buffer[fd].tail))
	{
		content = malloc(sizeof(char) * (GNL_BUFFER_SIZE + 1));
		if (!content)
			return (gnl_clear_buffer(&buffer[fd]), -1);
		bytesread = read(fd, content, GNL_BUFFER_SIZE);
		if (bytesread == -1)
			return (free(content), gnl_clear_buffer(&buffer[fd]), -1);
		else if (bytesread == 0)
			free(content);
		else if (bytesread > 0)
		{
			if (gnl_add_node(&buffer[fd], content) == EXIT_FAILURE)
				return (free(content), gnl_clear_buffer(&buffer[fd]), -1);
			buffer[fd].tail->size = bytesread;
		}
	}
	return (get_line(&buffer[fd], line));
}
