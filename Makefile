# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nhariman <nhariman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/31 23:42:48 by nhariman      #+#    #+#                  #
#    Updated: 2020/07/29 18:17:24 by nhariman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COMPILE = gcc

FLAGS = -Wall -Werror -Wextra

CFILES = 	main.c \
			parser.c \
			savers.c \
			valid_input.c \
			valid_map.c \
			error_messages.c \
			checker.c \
			colour.c \
			clear_structs.c \
			floodfill.c \
			get_next_line.c 

#CBONUS =

OFILES = $(CFILES:.c=.o)

OBONUS = $(CBONUS:.c=.o)

NAME = cub3d

all: $(NAME)

$(NAME): $(OFILES) libft/libft.a
	@$(COMPILE) $(OFILES) libft/libft.a -o $@

libft/libft.a:
	@cd libft && $(MAKE)

%.o: %.c libft.h
	@$(COMPILE) -c $(FLAGS) -o $@ -c $<

clean:
	@$(RM) $(OFILES) $(OBONUS) 
	@cd libft && $(MAKE) clean

fclean: clean
	@$(RM) $(NAME) 
	@cd libft && $(MAKE) fclean

re: fclean all

bonus: $(OFILES) $(OBONUS) libft/libft.a
	@$(COMPILE) $(OFILES) libft/libft.a -o $@
