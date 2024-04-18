/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/02/19 14:41:02 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/04/18 20:27:02 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "utils.h"
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <sys/param.h>
# include <stdint.h>
# include <stddef.h>
# include <wchar.h>

# define PRINT_ERROR -1
# define NULL_MSG "(null)"
# define NIL_MSG "(nil)"

# define BASE_8 "01234567"
# define BASE_10 "0123456789"
# define BASE_16_LOW "0123456789abcdef"
# define BASE_16_UP "0123456789ABCDEF"

# define FLAGS "-+ #0"

# define LENGTH_0 ""
# define LENGTH_1 "hh"
# define LENGTH_2 "h"
# define LENGTH_3 "ll"
# define LENGTH_4 "l"
# define LENGTH_5 "j"
# define LENGTH_6 "z"
# define LENGTH_7 "t"
# define LENGTH_8 "L"

typedef enum s_length
{
	NO_LEN,
	HH_LOW_LEN,
	H_LOW_LEN,
	LL_LOW_LEN,
	L_LOW_LEN,
	J_LOW_LEN,
	Z_LOW_LEN,
	T_LOW_LEN,
	L_UP_LEN,
}	t_length;

# define SPECIFIERS "cspdiuxX%nok"

struct					s_elem;
typedef struct s_elem	t_elem;
struct					s_buffer;
typedef struct s_buffer	t_buffer;

typedef int				(*t_handler)(va_list, t_elem, t_buffer *);

struct	s_elem
{
	bool		is_minus;
	bool		is_plus;
	bool		is_space;
	bool		is_hash;
	bool		is_zero;
	int			width;
	bool		is_dot;
	int			precision;
	t_length	length;
	char		formatid;
	t_handler	formatid_handler;
};

typedef struct s_node
{
	char				c;
	struct s_node		*next;
}	t_node;

struct s_buffer
{
	t_node	*head;
	t_node	*tail;
	int		size;
};

/* Buffer Management */
t_node		*new_node(char c);
int			add_node(t_buffer *buffer, char c);
int			add_nodes(t_buffer *buffer, char *str);
void		add_back(t_buffer *buffer, t_node *new);
void		clear_buffer(t_buffer buffer);
void		buffer_to_string(char *str, size_t size, t_buffer buffer);
int			flush(t_buffer buffer, int fd);

/* Parsing */
// Elem
const char	*parse_elem(const char *ptr, t_elem *elem, va_list args);
// Flags
const char	*parse_flags(const char *ptr, t_elem *elem, va_list args);
const char	*set_minus(const char *ptr, t_elem *elem);
const char	*set_plus(const char *ptr, t_elem *elem);
const char	*set_space(const char *ptr, t_elem *elem);
const char	*set_hash(const char *ptr, t_elem *elem);
const char	*set_zero(const char *ptr, t_elem *elem);
// Width
const char	*parse_width(const char *ptr, t_elem *elem, va_list args);
// Precision
const char	*parse_precision(const char *ptr, t_elem *elem, va_list args);
// Length
const char	*parse_length(const char *ptr, t_elem *elem, va_list args);
// Format identifier
const char	*parse_formatid(const char *ptr, t_elem *elem, va_list args);
// Utils
const char	*process_width(const char *ptr, uintmax_t *width, va_list args);

/* Execution */
int			formatid_c(va_list args, t_elem elem, t_buffer *buffer);
int			formatid_s(va_list args, t_elem elem, t_buffer *buffer);
int			formatid_p(va_list args, t_elem elem, t_buffer *buffer);
int			formatid_d(va_list args, t_elem elem, t_buffer *buffer);
int			formatid_u(va_list args, t_elem elem, t_buffer *buffer);
int			formatid_x(va_list args, t_elem elem, t_buffer *buffer);
int			formatid_percent(va_list args, t_elem elem, t_buffer *buffer);
int			formatid_n(va_list args, t_elem elem, t_buffer *buffer);
int			formatid_o(va_list args, t_elem elem, t_buffer *buffer);
int			formatid_k(va_list args, t_elem elem, t_buffer *buffer);
// Handle Unsigned
int			len_unsigned(uintmax_t nb, char *base, t_elem elem);
int			add_unsigned_nb(uintmax_t nb, char *base, t_elem elem, \
				t_buffer *buffer);
int			check_prefix_width(uintmax_t nb, t_elem elem);
int			check_prefix_precision(uintmax_t nb, t_elem elem);
int			add_prefix(uintmax_t nb, t_elem elem, t_buffer *buffer);
uintmax_t	handle_length_unsigned(va_list args, t_elem elem);
int			handle_unsigned(uintmax_t nb, char *base, t_elem elem, \
				t_buffer *buffer);
// Handle Signed
intmax_t	handle_length_signed(va_list args, t_elem elem);
int			len_signed(intmax_t nb, char *base, t_elem elem);
int			add_signed_nb(intmax_t nb, char *base, t_elem elem, \
				t_buffer *buffer);
int			handle_signed(intmax_t nb, char *base, t_elem elem, \
				t_buffer *buffer);
// Utils
int			fill_width(t_buffer *buffer, int amount, char filler);

/* Print */
// Buffer loader
int			ft_print(t_buffer *buffer, const char *format, va_list args);
// Print functions
int			ft_printf(const char *format, ...);
int			ft_dprintf(int fd, const char *format, ...);
int			ft_vprintf(const char *format, va_list args);
int			ft_vdprintf(int fd, const char *format, va_list args);
int			ft_sprintf(char *str, const char *format, ...);
int			ft_snprintf(char *str, size_t size, const char *format, ...);
int			ft_vsprintf(char *str, const char *format, va_list args);
int			ft_vsnprintf(char *str, size_t size, const char *format, \
			va_list args);

#endif
