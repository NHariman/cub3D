# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nhariman <nhariman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/31 23:42:48 by nhariman      #+#    #+#                  #
#    Updated: 2020/08/15 21:41:35 by nhariman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COMPILE = gcc

FLAGS = -Wall -Werror -Wextra

PARSER = 	srcs/main.c \
			srcs/parser/parser.c \
			srcs/parser/savers.c \
			srcs/parser/checker.c \
			srcs/parser/get_next_line.c


VALID =		srcs/valid_input/valid_input.c \
			srcs/valid_input/valid_map.c \
			srcs/valid_input/floodfill.c \
			srcs/valid_input/colour.c 

ERROR =		srcs/errors/error_messages.c \
			srcs/errors/map_errors.c \
			srcs/errors/more_errors.c \
			srcs/errors/clear_structs.c

RAYCAST =	srcs/raycasting/setup_raycasting.c \
			srcs/raycasting/window.c \
			srcs/raycasting/textures.c \
			srcs/raycasting/raycasting.c \
			srcs/raycasting/calc.c \
			srcs/raycasting/key_input.c \
			srcs/raycasting/movement.c \
			srcs/raycasting/background.c \
			srcs/raycasting/giant_fucking_function.c

#CBONUS =

OPARSER = 	$(PARSER:.c=.o)

OVALID =	$(VALID:.c=.o)

OERROR =	$(ERROR:.c=.o)

ORAYCAST =	$(RAYCAST:.c=.o)

OBONUS = 	$(CBONUS:.c=.o)

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
	@echo "\n***testing: invalid_rgb_input.cub"
	./cub3d srcs/maps/invalid_rgb_input.cub

$(NAME): $(OPARSER) $(OVALID) $(OERROR) $(ORAYCAST) srcs/libft/libft.a libmlx.dylib
	@$(COMPILE) $(OPARSER) $(OVALID) $(OERROR) $(ORAYCAST) srcs/libft/libft.a libmlx.dylib -o $@

libmlx.dylib:
	@cd srcs/mlx && $(MAKE) && mv libmlx.dylib ../../

srcs/libft/libft.a:
	@cd srcs/libft && $(MAKE)

%.o: %.c srcs/cub.h
	@$(COMPILE) -c $(FLAGS) -o $@ -c $<

clean:
	@$(RM) $(OPARSER) $(OVALID) $(OERROR) $(OBONUS) $(ORAYCAST)
	@cd srcs/libft && $(MAKE) clean
	@cd srcs/mlx && $(MAKE) clean

fclean: clean
	@$(RM) $(NAME) libmlx.dylib
	@cd srcs/libft && $(MAKE) fclean

re: fclean all

bonus: $(OPARSER) $(OVALID) $(OERROR) $(OBONUS) $(ORAYCAST) srcs/libft/libft.a
	@$(COMPILE) $(OPARSER) $(OVALID) $(OERROR) srcs/libft/libft.a -o $@
