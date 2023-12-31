/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 04:43:23 by chlimous          #+#    #+#             */
/*   Updated: 2023/12/31 04:44:00 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "list.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 100
# endif

ssize_t		get_next_line(int fd, char **line);
bool		is_eol(t_list *node);
size_t		get_eol_index(t_list *node);
void		clear_lst_but_last(t_advlist *advlst);

#endif
