### Executable ###
NAME	= fractol

### Directory ###
MLX_PATH	= mlx_Linux/
LIBFT_PATH	= libft/


### Source Files ###
FRACT_SRCS = fractol.c ft_hook.c ft_putpix.c ft_render.c\
			 libft/ft_itoa.c libft/ft_strlen.c

### Compilation ###
CC		= gcc
RM		= rm -f
FLAGS	= -Wall -Wextra -Werror
MCFLAG	= -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT_SRCS = ft_itoa.c ft_strlen.c

#SRCS = $(FRACT_SRCS)

#OBJS = $(SRCS:.c=.o)

all:
	$(CC) $(MCFLAG) $(FRACT_SRCS) -o $(NAME)
	# $(CC) $(FRACT_SRCS) $(MLX_FLAGS) -o $(NAME)

#all: $(NAME)

#%.o:%.c
#	$(CC) -c $< -o $@

#$(NAME): $(OBJS)
#	$(CC) $(OBJS) $(FLAGS) $(MLX_FLAGS) $(MLX_HEAD) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
