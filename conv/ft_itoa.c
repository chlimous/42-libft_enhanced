/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:29:46 by chlimous          #+#    #+#             */
/*   Updated: 2023/11/21 23:20:16 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	size_alloc(ssize_t n)
{
	unsigned int	size;

	size = 2;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n / 10 != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	unsigned int	size;
	unsigned int	i;
	char			*res;
	ssize_t			ntemp;

	ntemp = n;
	size = size_alloc(ntemp);
	res = malloc(sizeof(char) * size);
	if (!res)
		return (NULL);
	if (ntemp < 0)
	{
		res[0] = '-';
		ntemp = -ntemp;
	}
	res[size - 1] = '\0';
	i = size - 2;
	while (ntemp / 10 != 0)
	{
		res[i] = ntemp % 10 + 48;
		ntemp /= 10;
		i--;
	}
	res[i] = ntemp % 10 + 48;
	return (res);
}
