/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   conv.h                                             :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/13 12:51:52 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/02/28 01:33:46 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#ifndef CONV_H
# define CONV_H

# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *nptr);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_itoa(int n);
int		ft_ascii_to_nb(char ascii);

#endif
