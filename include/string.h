/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/13 13:00:57 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/04/18 21:04:05 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char const *sep_charset);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(size_t, char));
void	ft_striteri(char *s, void (*f)(size_t, char *));
char	*ft_strncpy(char *dest, char *src, size_t size);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strndup(const char *src, size_t size);
char	*ft_strdup_cat(const char *str1, const char *str2);
int		ft_strcmp(const char *s1, const char *s2);

#endif
