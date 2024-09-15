# **************************************************************************** #
#									       #
#							  :::	   ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#						      +:+ +:+	      +:+      #
#    By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	       #
#						  +#+#+#+#+#+	+#+	       #
#    Created: 2023/12/13 15:29:55 by chlimous	       #+#    #+#	       #
#    Updated: 2024/09/15 04:28:14 by chlimous         ###   ########.fr        #
#									       #
# **************************************************************************** #

NAME = libft.a

SRCS += $(addprefix list/, ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c)
SRCS += $(addprefix print/, ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c)
SRCS += $(addprefix mem/, ft_bzero.c ft_calloc.c ft_free_pp.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c)
SRCS += $(addprefix conv/, ft_atoi.c ft_atof.c ft_itoa.c ft_tolower.c ft_toupper.c ft_ascii_to_nb.c)
SRCS += $(addprefix check/, ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c)
SRCS += $(addprefix str/, ft_split.c ft_strchr.c ft_strcpy.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_strncpy.c ft_strndup.c ft_strdup_cat.c ft_strcmp.c ft_wcslen.c)
SRCS += $(addprefix tab/, ft_rev_int_tab.c ft_rev_long_tab.c)
SRCS += $(addprefix maths/, ft_isnan.c)

SRCS += $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c buffer.c)

SRCS += $(addprefix ft_printf/, ft_printf.c ft_printf2.c ft_printf3.c load_buffer.c)
SRCS += $(addprefix ft_printf/buffer/, add_back.c add_node.c buffer_to_string.c clear_buffer.c flush.c new_node.c)
SRCS += $(addprefix ft_printf/parser/, parse_elem.c parse_flags.c set_flags.c parse_width.c parse_precision.c parse_length.c parse_formatid.c utils.c)
SRCS += $(addprefix ft_printf/exec/, formatid_c.c formatid_s.c formatid_p.c formatid_di.c formatid_u.c formatid_x.c formatid_percent.c formatid_fe.c formatid_n.c formatid_o.c formatid_k.c utils.c handle_unsigned.c handle_unsigned2.c handle_signed.c handle_signed2.c handle_float.c handle_float2.c handle_float3.c handle_float4.c handle_float5.c)

OBJS = $(SRCS:.c=.o)

INCLUDE = include

INCLUDES = -I $(INCLUDE) -I ft_printf/include -I get_next_line/include 

CC = cc

CFLAGS = -Wall -Wextra -Werror

MAKEFLAGS += --no-print-directory

%.o: %.c $(INCLUDE) ft_printf/include get_next_line/include
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
