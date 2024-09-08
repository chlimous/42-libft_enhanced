/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:50:18 by chlimous          #+#    #+#             */
/*   Updated: 2024/05/01 20:50:23 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 100
# endif

# define GNL_FLUSH -1

typedef struct s_gnl_node
{
	char				*content;
	ssize_t				size;
	struct s_gnl_node	*next;
}	t_gnl_node;

typedef struct s_gnl_buffer
{
	t_gnl_node	*head;
	t_gnl_node	*tail;
	size_t		size;
}	t_gnl_buffer;

/* Buffer */
int		gnl_add_node(t_gnl_buffer *buffer, char *content);
void	gnl_partial_clear_buffer(t_gnl_buffer *buffer);
void	gnl_clear_buffer(t_gnl_buffer *buffer);

/* Utils */
bool	gnl_is_eol(t_gnl_node *node);
ssize_t	gnl_eol_index(t_gnl_node *node);
void	gnl_cpy(char *dest, const char *src, ssize_t size);

/* get_next_line */
size_t	get_next_line(int fd, char **line, int flag);

#endif
