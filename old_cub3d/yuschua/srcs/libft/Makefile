# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybakker <ybakker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 10:51:58 by ybakker           #+#    #+#              #
#    Updated: 2019/11/21 15:33:15 by ybakker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRC		=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
			ft_putnbr_fd.c ft_memchr.c ft_calloc.c ft_putchar_fd.c\
			ft_putendl_fd.c ft_putstr_fd.c ft_strlen.c ft_strlcpy.c\
			ft_strlcat.c ft_strrchr.c ft_strnstr.c ft_itoa.c ft_split.c\
			ft_strchr.c ft_strdup.c ft_strjoin.c ft_strmapi.c ft_strtrim.c\
			ft_substr.c ft_memcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c\
			ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c\
			ft_isdigit.c
BONUS_SRC	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OFILES			=	$(SRC:%.c=%.o)
BONUS_OFILES	=	$(BONUS_SRC:%.c=%.o)
FLAGS			=	-Wall -Wextra -Werror
AR_COMMAND		=	ar rcsv

all: $(NAME)

$(NAME): $(OFILES)
	$(AR_COMMAND) $(NAME) $(OFILES)

%.o: %.c
	@gcc -o $@ -c $< $(FLAGS)

clean:
	rm -f $(OFILES) $(BONUS_OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OFILES) $(BONUS_OFILES)
	$(AR_COMMAND) $(NAME) $(OFILES) $(BONUS_OFILES)
