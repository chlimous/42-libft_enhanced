/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/29 18:07:22 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/12/31 04:14:09 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static int	trim_static(t_advlist *advlst, ssize_t eol_index)
{
	char	*content;
	ssize_t	len;

	clear_lst_but_last(advlst);
	len = ft_strlen(advlst->head->content) - eol_index - 1;
	if (len > 0)
	{
		content = malloc(sizeof(char) * (len + 1));
		if (!content)
			return (1);
		ft_strncpy(content, advlst->head->content + eol_index + 1, len + 1);
		free(advlst->head->content);
		advlst->head->content = content;
	}
	else
		ft_advlstclear(advlst);
	return (0);
}

static void	list_to_string(t_advlist *advlst, char **line, ssize_t eol_index)
{
	ssize_t	len;
	t_list	*current;
	size_t	i;

	i = 0;
	len = 0;
	current = advlst->head;
	while (current)
	{
		if (i + 1 == advlst->size)
			ft_strlcpy(*line + len, current->content, eol_index + 2);
		else if (i == 0)
		{
			ft_strncpy(*line, current->content, ft_strlen(current->content));
			len += ft_strlen(current->content);
		}
		else
		{
			ft_strncpy(*line + len, current->content, BUFFER_SIZE);
			len += BUFFER_SIZE;
		}
		i++;
		current = current->next;
	}
}

static	size_t	get_line_len(t_advlist *advlst, ssize_t eol_index)
{
	ssize_t	len;

	if (advlst->size == 1)
		len = eol_index + 1;
	else if (advlst->size == 2)
		len = ft_strlen(advlst->head->content) + (eol_index + 1);
	else
		len = ft_strlen(advlst->head->content) + \
			((advlst->size - 2) * BUFFER_SIZE) + (eol_index + 1);
	return (len);
}

static ssize_t	build_line(t_advlist *advlst, char **line)
{
	ssize_t	len;
	ssize_t	eol_index;

	eol_index = get_eol_index(advlst->tail);
	len = get_line_len(advlst, eol_index);
	*line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (ft_advlstclear(advlst), -1);
	list_to_string(advlst, line, eol_index);
	if (trim_static(advlst, eol_index))
		return (ft_advlstclear(advlst), free(*line), -1);
	return (len);
}

ssize_t	get_next_line(int fd, char **line)
{
	static t_advlist	advlst[FD_MAX + 1];
	char				*buffer;
	ssize_t				bytesread;

	bytesread = 1;
	while (bytesread > 0 && !is_eol(advlst[fd].tail))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (ft_advlstclear(&advlst[fd]), -1);
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
			return (ft_advlstclear(&advlst[fd]), free(buffer), -1);
		if (bytesread > 0)
		{
			buffer[bytesread] = '\0';
			if (ft_advlstadd_back(&advlst[fd], ft_lstnew(buffer)))
				return (ft_advlstclear(&advlst[fd]), free(buffer), -1);
		}
		if (!advlst[fd].size)
			return (free(buffer), 0);
		if (!bytesread)
			free(buffer);
	}
	return (build_line(&advlst[fd], line));
}
