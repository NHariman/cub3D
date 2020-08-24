# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ybakker <ybakker@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/05 10:59:00 by ybakker       #+#    #+#                  #
#    Updated: 2020/07/27 19:53:51 by ybakker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = ./srcs/cube_functions/main.c\
		./srcs/cube_functions/create_bmp.c\
		./srcs/cube_functions/settings/error.c\
		./srcs/cube_functions/settings/input_file_to_image.c\
		./srcs/cube_functions/settings/key_input.c\
		./srcs/cube_functions/settings/keys.c\
		./srcs/cube_functions/settings/set_location.c\
		./srcs/cube_functions/settings/set_value_texture.c\
		./srcs/cube_functions/settings/set_value.c\
		./srcs/cube_functions/utills/check_fill.c\
		./srcs/cube_functions/utills/ft_check_empty_line.c\
		./srcs/cube_functions/utills/functions_pfour.c\
		./srcs/cube_functions/utills/functions_pthree.c\
		./srcs/cube_functions/utills/functions_ptwo.c\
		./srcs/cube_functions/utills/functions.c\
		./srcs/cube_functions/utills/map_check.c\
		./srcs/cube_functions/utills/utills_five.c\
		./srcs/cube_functions/utills/utills_six.c\
		./srcs/cube_functions/casting/raycasting_sprites.c\
		./srcs/cube_functions/casting/raycasting_texture_input.c\
		./srcs/cube_functions/casting/raycasting_texture.c\
		./srcs/cube_functions/casting/render_next_frame_structure.c\
		./srcs/cube_functions/casting/texture.c\
		./srcs/cube_functions/readmap/get_info/ft_read_c.c\
		./srcs/cube_functions/readmap/get_info/ft_read_ea.c\
		./srcs/cube_functions/readmap/get_info/ft_read_f.c\
		./srcs/cube_functions/readmap/get_info/ft_read_no.c\
		./srcs/cube_functions/readmap/get_info/ft_read_r.c\
		./srcs/cube_functions/readmap/get_info/ft_read_s.c\
		./srcs/cube_functions/readmap/get_info/ft_read_so.c\
		./srcs/cube_functions/readmap/get_info/ft_read_we.c\
		./srcs/cube_functions/readmap/get_info/space_cubemap.c\
		./srcs/cube_functions/readmap/get_info/get_map.c\
		./srcs/cube_functions/readmap/ft_read_map.c\
		./srcs/cube_functions/readmap/ft_info_parser_check.c\
		./srcs/get_next_line/get_next_line_utils.c\
		./srcs/get_next_line/get_next_line.c\

OBJ	= $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = srcs/libft
MLX = mlx
.PHONY: all clean fclean re
all: $(NAME)
$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@make -C $(MLX)
	@cp mlx/libmlx.dylib ./libmlx.dylib
	@cp srcs/libft/libft.a ./libft.a
	@$(CC) -L mlx/ -lmlx -framework OpenGL -framework AppKit  \
	$(OBJ) libft.a -o $(NAME)
%.o: %.c
	@gcc $(CFLAGS) -I mlx -I srcs/libft -c $< -o $@
clean:
	@$(RM) $(OBJ)
	@make clean -C $(LIBFT)
	@make clean -C $(MLX)
	@$(RM) screen.bmp
fclean: clean
	@$(RM) $(BMP)
	@$(RM) $(NAME)
	@$(RM) libmlx.dylib
	@$(RM) libft.a
	@make fclean -C $(LIBFT)
re: fclean all
