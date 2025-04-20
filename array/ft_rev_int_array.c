/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 01:42:04 by chlimous          #+#    #+#             */
/*   Updated: 2025/04/20 19:39:35 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_rev_int_array(int *array, size_t size)
{
	size_t	i;
	int		temp;

	i = 0;
	while (i < size / 2)
	{
		temp = array[i];
		array[i] = array[size - i - 1];
		array[size - i - 1] = temp;
		++i;
	}
}
