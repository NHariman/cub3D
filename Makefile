# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nhariman <nhariman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/31 23:42:48 by nhariman      #+#    #+#                  #
#    Updated: 2020/07/10 18:59:24 by nhariman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COMPILE = gcc

FLAGS = -Wall -Werror -Wextra

CFILES = main.c parser.c

#CBONUS =

OFILES = $(CFILES:.c=.o)

OBONUS = $(CBONUS:.c=.o)

NAME = cub3d.a

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $@ $^

%.o: %.c libft.h
	$(COMPILE) -c $(FLAGS) -Imlx -Ilft -o $@ -c $<

clean:
	$(RM) $(OFILES) $(OBONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OFILES) $(OBONUS)
	ar rcs $(NAME) $^
