# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nhariman <nhariman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/31 23:42:48 by nhariman      #+#    #+#                  #
#    Updated: 2020/08/03 22:54:02 by nhariman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COMPILE = gcc

FLAGS = -Wall -Werror -Wextra

PARSER = 	srcs/main.c \
			srcs/parser/parser.c \
			srcs/parser/savers.c \
			srcs/parser/checker.c \
			srcs/parser/colour.c \
			srcs/parser/get_next_line.c


VALID =		srcs/valid_input/valid_input.c \
			srcs/valid_input/valid_map.c \
			srcs/valid_input/floodfill.c 

ERROR =		srcs/errors/error_messages.c \
			srcs/errors/map_errors.c \
			srcs/errors/more_errors.c \
			srcs/errors/clear_structs.c

#CBONUS =

OPARSER = 	$(PARSER:.c=.o)

OVALID =	$(VALID:.c=.o)

OERROR =	$(ERROR:.c=.o)

OBONUS = $(CBONUS:.c=.o)

NAME = cub3d

all: $(NAME)

test: $(NAME)
	@make re
	./cub3d srcs/maps/test.cub

valid: $(NAME)
	@make re
	./cub3d srcs/maps/valid_map_noise.cub

invalid: $(NAME)
	@make re
	@echo "this will test **INVALID MAPS**, the program should fail."
	@echo "****testing: map_invalid_doubles_.cub"
	./cub3d srcs/maps/invalid_map_doubles.cub
	@echo "\n***testing: invalid_map_notclosed.cub"
	./cub3d srcs/maps/invalid_map_notclosed.cub
	@echo "\n***testing: invalid_map_noise.cub"
	./cub3d srcs/maps/invalid_map_noise.cub
	@echo "\n***testing: invalid_map_noise2.cub"
	./cub3d srcs/maps/invalid_map_noise2.cub
	@echo "\n***testing: invalid_map_noise3.cub"
	./cub3d srcs/maps/invalid_map_noise3.cub
	@echo "\n***testing: double_input.cub"
	./cub3d srcs/maps/double_input.cub
	@echo "\n***testing: empty_file.cub"
	./cub3d srcs/maps/empty_file.cub
	@echo "\n***testing: negative_input.cub"
	./cub3d srcs/maps/negative_input.cub

$(NAME): $(OPARSER) $(OVALID) $(OERROR) srcs/libft/libft.a
	@$(COMPILE) $(OPARSER) $(OVALID) $(OERROR) srcs/libft/libft.a -o $@

srcs/libft/libft.a:
	@cd srcs/libft && $(MAKE)

%.o: %.c libft.h
	@$(COMPILE) -c $(FLAGS) -o $@ -c $<

clean:
	@$(RM) $(OPARSER) $(OVALID) $(OERROR) $(OBONUS) 
	@cd srcs/libft && $(MAKE) clean

fclean: clean
	@$(RM) $(NAME) 
	@cd srcs/libft && $(MAKE) fclean

re: fclean all

bonus: $(OPARSER) $(OVALID) $(OERROR) $(OBONUS) srcs/libft/libft.a
	@$(COMPILE) $(OPARSER) $(OVALID) $(OERROR) srcs/libft/libft.a -o $@
