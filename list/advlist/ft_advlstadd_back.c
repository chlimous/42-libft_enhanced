/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advlstadd_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 04:41:25 by chlimous          #+#    #+#             */
/*   Updated: 2023/12/31 04:41:27 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_advlstadd_back(t_advlist *advlst, t_list *new)
{
	if (!new)
		return (1);
	if (advlst->tail)
		advlst->tail->next = new;
	else
		advlst->head = new;
	advlst->tail = new;
	advlst->size += 1;
	return (0);
}
