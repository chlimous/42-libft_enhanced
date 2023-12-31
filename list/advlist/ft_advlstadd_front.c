/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advlstadd_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 04:41:29 by chlimous          #+#    #+#             */
/*   Updated: 2023/12/31 04:41:30 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_advlstadd_front(t_advlist *advlst, t_list *new)
{
	if (!new)
		return (1);
	new->next = advlst->head;
	advlst->head = new;
	if (!advlst->tail)
		advlst->tail = new;
	advlst->size += 1;
	return (0);
}
