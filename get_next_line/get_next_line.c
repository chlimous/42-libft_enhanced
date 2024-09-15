/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:35:18 by chlimous          #+#    #+#             */
/*   Updated: 2024/09/15 04:30:36 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static int	trim_buffer(t_buffer *buffer, ssize_t eol_index)
{
	char	*content;
	ssize_t	len;

	partial_clear_buffer(buffer);
	len = buffer->head->size - eol_index - 1;
	if (len > 0)
	{
		content = malloc(sizeof(char) * len);
		if (!content)
			return (EXIT_FAILURE);
		cpy(content, buffer->head->content + eol_index + 1, len);
		free(buffer->head->content);
		buffer->head->content = content;
		buffer->head->size = len;
	}
	else
		clear_buffer(buffer);
	return (EXIT_SUCCESS);
}

static size_t	line_len(t_buffer *buffer, ssize_t eol_index)
{
	size_t	size;

	size = eol_index + 1;
	if (buffer->size >= 2)
		size += buffer->head->size;
	if (buffer->size > 2)
		size += (buffer->size - 2) * BUFFER_SIZE;
	return (size);
}

static void	buffer_to_string(t_buffer buffer, char *line, \
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
			cpy(line + line_i, buffer.head->content, eol_index + 1);
			line[line_i + (eol_index + 1)] = '\0';
		}
		else if (node_i == 0)
		{
			cpy(line, buffer.head->content, buffer.head->size);
			line_i += buffer.head->size;
		}
		else
		{
			cpy(line + line_i, buffer.head->content, BUFFER_SIZE);
			line_i += BUFFER_SIZE;
		}
		++node_i;
		buffer.head = buffer.head->next;
	}
}

static size_t	get_line(t_buffer *buffer, char **line)
{
	size_t	len;
	ssize_t	eol_index;

	if (buffer->size == 0)
		return (0);
	eol_index = get_eol_index(buffer->tail);
	len = line_len(buffer, eol_index);
	*line = malloc(sizeof(char) * (len + 1));
	if (!*line)
		return (clear_buffer(buffer), -1);
	buffer_to_string(*buffer, *line, eol_index);
	if (trim_buffer(buffer, eol_index) == EXIT_FAILURE)
		return (free(*line), clear_buffer(buffer), -1);
	return (len);
}

size_t	get_next_line(int fd, char **line, int flag)
{
	static t_buffer		buffer[FD_MAX + 1];
	ssize_t				bytesread;
	char				*content;

	if (flag == FLUSH)
		return (clear_buffer(&buffer[fd]), 0);
	bytesread = 1;
	while (bytesread > 0 && !is_eol(buffer[fd].tail))
	{
		content = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!content)
			return (clear_buffer(&buffer[fd]), -1);
		bytesread = read(fd, content, BUFFER_SIZE);
		if (bytesread == -1)
			return (free(content), clear_buffer(&buffer[fd]), -1);
		else if (bytesread == 0)
			free(content);
		else if (bytesread > 0)
		{
			if (add_node(&buffer[fd], content) == EXIT_FAILURE)
				return (free(content), clear_buffer(&buffer[fd]), -1);
			buffer[fd].tail->size = bytesread;
		}
	}
	return (get_line(&buffer[fd], line));
}
