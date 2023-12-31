/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advlstclear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 04:41:32 by chlimous          #+#    #+#             */
/*   Updated: 2023/12/31 04:41:33 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_advlstclear(t_advlist *advlst)
{
	t_list	*temp;

	while (advlst->head)
	{
		temp = advlst->head->next;
		free(advlst->head->content);
		free(advlst->head);
		advlst->head = temp;
	}
	advlst->tail = NULL;
	advlst->size = 0;
}
