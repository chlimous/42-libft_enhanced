/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   flush.c                                            :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/03/10 19:35:39 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/04/13 20:23:52 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "ft_printf.h"

/******************************************************************************
 * @brief Writes buffer data to the file descriptor
 * 
 * @param buffer Buffer
 * @param fd Destination file descriptor
 * @return int Exit status
******************************************************************************/
int	pf_flush(t_pf_buffer buffer, int fd)
{
	char	*tmp;

	if (buffer.size == 0)
		return (write(fd, "", 0));
	tmp = malloc(sizeof(char) * (buffer.size + 1));
	if (!tmp)
		return (pf_clear_buffer(buffer), EXIT_FAILURE);
	pf_buffer_to_string(tmp, (size_t)INT_MAX + 1, buffer);
	if (write(fd, tmp, buffer.size) != buffer.size)
		return (free(tmp), EXIT_FAILURE);
	return (free(tmp), EXIT_SUCCESS);
}
