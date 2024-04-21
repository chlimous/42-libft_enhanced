/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/31 02:02:23 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/04/21 20:03:36 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

size_t	get_line_len(t_advlist *advlst, ssize_t eol_index)
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
