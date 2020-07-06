# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nhariman <nhariman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/31 23:42:48 by nhariman      #+#    #+#                  #
#    Updated: 2020/07/06 16:59:39 by nhariman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COMPILE = gcc

FLAGS = -Wall -Werror -Wextra

#CFILES = 

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
