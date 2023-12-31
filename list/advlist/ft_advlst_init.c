/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advlst_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 04:41:21 by chlimous          #+#    #+#             */
/*   Updated: 2023/12/31 04:41:22 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_advlst_init(t_advlist *advlst)
{
	advlst->head = NULL;
	advlst->tail = NULL;
	advlst->size = 0;
}
