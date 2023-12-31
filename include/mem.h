/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/13 12:43:02 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/12/31 05:03:26 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include <stdlib.h>
# include <unistd.h>

void	ft_bzero(void *mem, size_t n);
void	*ft_memset(void *mem, int byte, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);

#endif
