PROG = fractol
PROG_BONUS = fractol_bonus
CC = cc
FLAGS = -Wall -Wextra -Werror  -Imlx_linux
SRC = fractol.c init.c utils.c init_julia.c event.c tchek_arg.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = burninship_bonus.c  init_bonus.c  event_bonus.c   utils_bonus.c fractol_bonus.c init_julia_bonus.c conex_bonus.c tchek_argc_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

LDFLAGS = -Lmlx_linux -lmlx -lXext -lX11 -lm -lz

NAME = $(PROG)
all : $(NAME)

$(PROG) : $(OBJ)
			$(CC) $(FLAGS) $(SRC) -o $(PROG) $(LDFLAGS)

bonus : $(PROG_BONUS)
$(PROG_BONUS) : $(OBJ_BONUS)
			$(CC) $(FLAGS) $(SRC_BONUS) -o $(PROG_BONUS) $(LDFLAGS)
clean :
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -rf $(OBJ) $(PROG) $(PROG_BONUS)
re : fclean all
