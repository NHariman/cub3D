# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nhariman <nhariman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/31 23:42:48 by nhariman       #+#    #+#                 #
#    Updated: 2020/03/11 13:54:41 by nhariman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COMPILE = 	gcc

FLAGS = 	-Wall -Werror -Wextra

CLIBFT = 	libft/ft_atoi.c \
			libft/ft_bzero.c \
			libft/ft_isalnum.c \
			libft/ft_isalpha.c\
			libft/ft_isascii.c \
			libft/ft_isdigit.c \
			libft/ft_isprint.c \
			libft/ft_memccpy.c \
			libft/ft_memchr.c \
			libft/ft_memcpy.c \
			libft/ft_memmove.c \
			libft/ft_memset.c \
			libft/ft_putchar_fd.c \
			libft/ft_putendl_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_strlen.c \
			libft/ft_tolower.c \
			libft/ft_toupper.c \
			libft/ft_memcmp.c \
			libft/ft_strdup.c \
			libft/ft_calloc.c \
			libft/ft_strchr.c \
			libft/ft_strrchr.c \
			libft/ft_strnstr.c \
			libft/ft_strlcpy.c \
			libft/ft_strncmp.c \
			libft/ft_strlcat.c \
			libft/ft_substr.c \
			libft/ft_strjoin.c \
			libft/ft_strtrim.c \
			libft/ft_split.c \
			libft/ft_itoa.c \
			libft/ft_strmapi.c

CPRINTF =	ft_printf.c \
			ft_printf_flags.c \
			ft_printf_hexflags.c \
			ft_printf_numflags.c \
			ft_printf_num.c \
			ft_printf_str.c

OLIBFT = $(CLIBFT:.c=.o)

OPRINTF = $(CPRINTF:.c=.o)

NAME = libftprintf.a

LIBFT = libft.a

LIBFTDIR = ./libft/

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR)

$(NAME): $(OLIBFT) $(OPRINTF)
	ar rcs $@ $^

%.o: %.c libftprintf.h ft_printf.h
	$(COMPILE) $(FLAGS) -o $@ -c $<

clean:
	$(RM) $(OPRINTF)
	make -s -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -s -C libft fclean

re: fclean all

lldb: fclean
	$(COMPILE) -g $(CLIBFT) $(CPRINTF) -I./
