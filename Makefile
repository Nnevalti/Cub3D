NAME		=	Cub3D

# COMPILER
CC			=	gcc

# FLAGS
$(CFLAGS)	:
				-Wall -Werror -Wextra

# HEADER
INC_DIR		=	./include
INC_NAME	=	header.h \
INC			=	-I $(addprefix $(INC_DIR)/, $INC_NAME)
# SOURCES
SRC_DIR		=	./src
SRC			=	main.c \
				exit_game.c \
				init.c \

# OBJETS
OBJS_NAME	=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(SRC_DIR)/, $(OBJS_NAME))

# MINILIBX LIB
MLX_DIR		=	./minilibx
MLX_INC		=	-I $(MLX_DIR)
MLX_LNK		=	-L$(MLX_DIR) -lmlx
MLX			=	$(addprefix $(MLX_DIR)/, libmlx.dylib)

# LIBFT LIB
FT_DIR		=	$(addprefix $(SRC_DIR)/, libft)
FT_INC		=	-I $(FT_DIR)
FT_LNK		=	-L $(FT_DIR) -lft
LIBFT		=	$(addprefix $(FT_DIR), libft.a)

# RULES
all			:	$(MLX) $(LIBFT) $(NAME)

$(MLX)		:
				@echo "\nCompiling $(MLX_DIR)..."
				@make -C $(MLX_DIR)

$(LIBFT)	:
				@echo "\nCompiling $(FT_DIR)..."
				@make -C $(FT_DIR)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(INC) $(FT_INC) $(MLX_INC) $(addprefix $(SRC_DIR)/, $(SRC)) $(FT_LNK) $(MLX_LNK) -o $(NAME)

clean		:
				@rm -rf $(OBJS)
				make clean -C $(FT_DIR)

fclean		:	clean
				@echo "\nCleaning Directories..."
				rm -f $(NAME)
				rm -f libmlx.dylib
				make fclean -C $(FT_DIR)
				make clean -C $(MLX_DIR)

re			:	fclean all
