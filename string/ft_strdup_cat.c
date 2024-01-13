/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_cat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 01:17:55 by chlimous          #+#    #+#             */
/*   Updated: 2024/01/13 01:48:57 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_cat(const char *str1, const char *str2)
{
	char	*dst;
	size_t	str1_size;
	size_t	str2_size;

	str1_size = ft_strlen(str1);
	str2_size = ft_strlen(str2);
	dst = malloc(sizeof(char) * (str1_size + str2_size + 1));
	if (!dst)
		return (NULL);
	ft_memcpy(dst, str1, str1_size);
	ft_memcpy(dst + str1_size, str2, str2_size + 1);
	return (dst);
}
