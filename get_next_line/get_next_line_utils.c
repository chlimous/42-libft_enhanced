/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/31 02:02:23 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/01/01 20:23:02 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

bool	gnl_is_eol(t_list *node)
{
	ssize_t	i;

	if (!node)
		return (false);
	i = 0;
	while (((char *)node->content)[i])
	{
		if (((char *)node->content)[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}

size_t	gnl_get_eol_index(t_list *node)
{
	ssize_t	i;

	i = 0;
	while (((char *)node->content)[i])
	{
		if (((char *)node->content)[i] == '\n')
			return (i);
		i++;
	}
	return (i - 1);
}

void	gnl_clear_lst_but_last(t_advlist *advlst)
{
	t_list	*current;
	t_list	*temp;

	current = advlst->head;
	while (current->next)
	{
		temp = current -> next;
		free(current->content);
		free(current);
		current = temp;
	}
	advlst->head = advlst->tail;
	advlst->size = 1;
}
