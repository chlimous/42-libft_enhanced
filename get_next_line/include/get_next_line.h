/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:50:18 by chlimous          #+#    #+#             */
/*   Updated: 2024/09/15 04:32:56 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 100
# endif

typedef struct s_node
{
	char				*content;
	ssize_t				size;
	struct s_node		*next;
}	t_node;

typedef struct s_buffer
{
	t_node	*head;
	t_node	*tail;
	size_t	size;
}	t_buffer;

// Buffer
int		add_node(t_buffer *buffer, char *content);
void	partial_clear_buffer(t_buffer *buffer);
void	clear_buffer(t_buffer *buffer);

// Utils
int		is_eol(t_node *node);
ssize_t	get_eol_index(t_node *node);
void	cpy(char *dest, const char *src, ssize_t size);

#endif
