/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/02/19 14:41:02 by chlimous	       #+#    #+#	      */
/*   Updated: 2024/09/08 22:46:50 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <math.h>
# include <sys/param.h>
# include <stdint.h>
# include <stddef.h>
# include <wchar.h>

# define PRINTF_ERROR -1

# define NULL_MSG "(null)"
# define NIL_MSG "(nil)"
# define INF_LOW_MSG "inf"
# define INF_UP_MSG "INF"
# define NAN_LOW_MSG "nan"
# define NAN_UP_MSG "NAN"

# define DEF_PRCS_FLOAT 6

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

typedef enum s_pf_length
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
}	t_pf_length;

# define SPECIFIERS "cspdiuxX%fFeEnok"

struct					s_pf_elem;
typedef struct s_pf_elem	t_pf_elem;
struct					s_pf_buffer;
typedef struct s_pf_buffer	t_pf_buffer;

typedef int				(*t_handler)(va_list, t_pf_elem *, t_pf_buffer *);

struct	s_pf_elem
{
	bool		is_minus;
	bool		is_plus;
	bool		is_space;
	bool		is_hash;
	bool		is_zero;
	int			width;
	bool		is_dot;
	int			precision;
	t_pf_length	length;
	char		formatid;
	t_handler	formatid_handler;
};

typedef struct s_pf_node
{
	char				c;
	struct s_pf_node		*next;
}	t_pf_node;

struct s_pf_buffer
{
	t_pf_node	*head;
	t_pf_node	*tail;
	int		size;
};

/* Buffer Management */
t_pf_node		*pf_new_node(char c);
int			pf_add_node(t_pf_buffer *buffer, char c);
int			pf_add_nodes(t_pf_buffer *buffer, char *str);
void		pf_add_back(t_pf_buffer *buffer, t_pf_node *new);
void		pf_clear_buffer(t_pf_buffer buffer);
void		pf_buffer_to_string(char *str, size_t size, t_pf_buffer buffer);
int			pf_flush(t_pf_buffer buffer, int fd);

/* Parsing */
// Elem
const char	*pf_parse_elem(const char *ptr, t_pf_elem *elem, va_list args);
// Flags
const char	*pf_parse_flags(const char *ptr, t_pf_elem *elem, va_list args);
const char	*pf_set_minus(const char *ptr, t_pf_elem *elem);
const char	*pf_set_plus(const char *ptr, t_pf_elem *elem);
const char	*pf_set_space(const char *ptr, t_pf_elem *elem);
const char	*pf_set_hash(const char *ptr, t_pf_elem *elem);
const char	*pf_set_zero(const char *ptr, t_pf_elem *elem);
// Width
const char	*pf_parse_width(const char *ptr, t_pf_elem *elem, va_list args);
// Precision
const char	*pf_parse_precision(const char *ptr, t_pf_elem *elem, va_list args);
// Length
const char	*pf_parse_length(const char *ptr, t_pf_elem *elem, va_list args);
// Format identifier
const char	*pf_parse_formatid(const char *ptr, t_pf_elem *elem, va_list args);
// Utils
const char	*pf_process_width(const char *ptr, uintmax_t *width, va_list args);

/* Execution */
int			pf_formatid_c(va_list args, t_pf_elem *elem, t_pf_buffer *buffer);
int			pf_formatid_s(va_list args, t_pf_elem *elem, t_pf_buffer *buffer);
int			pf_formatid_p(va_list args, t_pf_elem *elem, t_pf_buffer *buffer);
int			pf_formatid_di(va_list args, t_pf_elem *elem, t_pf_buffer *buffer);
int			pf_formatid_u(va_list args, t_pf_elem *elem, t_pf_buffer *buffer);
int			pf_formatid_x(va_list args, t_pf_elem *elem, t_pf_buffer *buffer);
int			pf_formatid_percent(va_list args, t_pf_elem *elem, t_pf_buffer *buffer);
int			pf_formatid_fe(va_list args, t_pf_elem *elem, t_pf_buffer *buffer);
int			pf_formatid_n(va_list args, t_pf_elem *elem, t_pf_buffer *buffer);
int			pf_formatid_o(va_list args, t_pf_elem *elem, t_pf_buffer *buffer);
int			pf_formatid_k(va_list args, t_pf_elem *elem, t_pf_buffer *buffer);
// Handle Unsigned
int			pf_len_unsigned(uintmax_t nb, char *base, t_pf_elem *elem);
int			pf_add_unsigned_nb(uintmax_t nb, char *base, t_pf_elem *elem, \
				t_pf_buffer *buffer);
int			pf_check_prefix_width(uintmax_t nb, t_pf_elem *elem);
int			pf_check_prefix_precision(uintmax_t nb, t_pf_elem *elem);
int			pf_add_prefix(uintmax_t nb, t_pf_elem *elem, t_pf_buffer *buffer);
uintmax_t	pf_handle_length_unsigned(va_list args, t_pf_elem *elem);
int			pf_handle_unsigned(uintmax_t nb, char *base, t_pf_elem *elem, \
				t_pf_buffer *buffer);
// Handle Signed
intmax_t	pf_handle_length_signed(va_list args, t_pf_elem *elem);
int			pf_len_signed(intmax_t nb, char *base, t_pf_elem *elem);
int			pf_add_signed_nb(intmax_t nb, char *base, t_pf_elem *elem, \
				t_pf_buffer *buffer);
int			pf_handle_signed(intmax_t nb, char *base, t_pf_elem *elem, \
				t_pf_buffer *buffer);
// Handle Float
int			pf_handle_float(long double nb, t_pf_elem *elem, t_pf_buffer *buffer);
int			pf_check_sign_float(long double nb, t_pf_elem *elem);
long double	pf_handle_length_float(va_list args, t_pf_elem *elem);
int			pf_abs_int(int nb);
int			pf_len_float(long double nb, t_pf_elem *elem);
int			pf_add_float_nb(long double nb, t_pf_elem *elem, t_pf_buffer *buffer);
int			pf_len_float_f(long double nb, t_pf_elem *elem);
int			pf_add_float_dec(long double nb, t_pf_elem *elem, t_pf_buffer *buffer);
int			pf_add_float_f(long double nb, t_pf_elem *elem, t_pf_buffer *buffer);
int			pf_len_float_e(long double nb, t_pf_elem *elem);
int			pf_add_float_e(long double nb, t_pf_elem *elem, t_pf_buffer *buffer);
// Utils
int			pf_fill_width(t_pf_buffer *buffer, int amount, char filler);

/* Print */
// Buffer loader
int			pf_load_buffer(t_pf_buffer *buffer, const char *format, va_list args);
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
int			ft_asprintf(char **str, const char *format, ...);
int			ft_vasprintf(char **str, const char *format, va_list args);

#endif
