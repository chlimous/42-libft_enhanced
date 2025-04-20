/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/07 00:26:57 by chlimous	       #+#    #+#	      */
/*   Updated: 2025/04/20 19:59:00 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <sys/types.h>
# include <stdarg.h>

// get_next_line
# define FLUSH -1

// check
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);

// conv
int		ft_ascii_to_nb(char ascii);
double	ft_atof(const char *nptr);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
int		ft_tolower(int c);
int		ft_toupper(int c);

// printf
int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_vprintf(const char *format, va_list args);
int		ft_vdprintf(int fd, const char *format, va_list args);
int		ft_sprintf(char *str, const char *format, ...);
int		ft_snprintf(char *str, size_t size, const char *format, ...);
int		ft_vsprintf(char *str, const char *format, va_list args);
int		ft_vsnprintf(char *str, size_t size, const char *format, \
			va_list args);
int		ft_asprintf(char **str, const char *format, ...);
int		ft_vasprintf(char **str, const char *format, va_list args);

// get_next_line
size_t	get_next_line(int fd, char **line, int flag);

// maths
int		ft_isnan(long double x);

// mem
void	ft_bzero(void *mem, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_free_pp(void **pp);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *mem, int byte, size_t n);

// print
ssize_t	ft_putchar_fd(char c, int fd);
ssize_t	ft_putendl_fd(char *str, int fd);
ssize_t	ft_putnbr_fd(int n, int fd);
ssize_t	ft_putstr_fd(char *str, int fd);

// str
void	ft_free_strs(char **strs);
char	**ft_split(char const *s, char const *sep_charset);
char	*ft_str_realloc(char *str, size_t size);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *src);
void	ft_striteri(char *s, void (*f)(size_t, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(size_t, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dest, char *src, size_t size);
char	*ft_strndup(const char *src, size_t size);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, size_t start, size_t len);
size_t	ft_wcslen(const wchar_t *str);

// array
void	ft_rev_int_array(int *tab, size_t size);

#endif
