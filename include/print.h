/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/13 12:41:07 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/12/13 12:43:47 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <unistd.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
