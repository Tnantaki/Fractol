### Executable ###
NAME	= fractol

### Directory ###
MLX_PATH	= mlx_Linux/
#LIBFT_PATH	= libft/


### Source Files ###
FRACT_SRCS = fractol.c ft_hook.c

### Compilation ###
CC		= gcc
RM		= rm -f
FLAGS	= -Wall -Wextra -Werror
MCFLAG	= -Lmlx -lmlx -framework OpenGL -framework AppKit

# UNAME = $(uname -s)
# ifeq ($(UNAME), Linux)
# 	MLX_DIR		= mlx_Linux
# 	MLX_FLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
# 	MLX_HEAD	= -Imlx_Linux
# else

# endif
#LIBFT_SRCS = ft_atoi.c ft_isdigit.c ft_strlen.c ft_split.c\
			ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c\
			ft_lstlast.c ft_lstbefore_last.c ft_delcont.c\
			ft_lstdelone.c ft_lstclear.c ft_lstsize.c


#ACTIONS_SRCS = ft_swap.c ft_rotate.c ft_reverse_rotate.c ft_push.c


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
