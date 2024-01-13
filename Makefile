# **************************************************************************** #
#									       #
#							  :::	   ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#						      +:+ +:+	      +:+      #
#    By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	       #
#						  +#+#+#+#+#+	+#+	       #
#    Created: 2023/12/13 15:29:55 by chlimous	       #+#    #+#	       #
#    Updated: 2024/01/13 01:47:56 by chlimous         ###   ########.fr        #
#									       #
# **************************************************************************** #

NAME = libft.a

SRCS += $(addprefix list/, ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c)
SRCS += $(addprefix list/advlist/, ft_advlst_init.c ft_advlstadd_back.c ft_advlstadd_front.c ft_advlstclear.c)
SRCS += $(addprefix print/, ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c)
SRCS += $(addprefix mem/, ft_bzero.c ft_calloc.c ft_free_pp.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c)
SRCS += $(addprefix conv/, ft_atoi.c ft_itoa.c ft_tolower.c ft_toupper.c)
SRCS += $(addprefix check/, ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c)
SRCS += $(addprefix string/, ft_split.c ft_strchr.c ft_strcpy.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_strncpy.c ft_strndup.c ft_strdup_cat.c)
SRCS += $(addprefix tab/, ft_rev_int_tab.c ft_rev_long_tab.c)
SRCS += $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)
SRCS += $(addprefix ft_printf/, ft_printf.c formatid_char.c formatid_string.c formatid_ptr.c formatid_intbase.c formatid_uintbase.c formatid_percent.c formatid_unknown.c)

OBJS = $(SRCS:.c=.o)

INCLUDE = include

CC = cc

CFLAGS = -Wall -Wextra -Werror

MAKEFLAGS += --no-print-directory

.c.o:
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
