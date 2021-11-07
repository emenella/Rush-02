GCC			=	gcc -g3 -fsanitize=address #-Wall -Werror -Wextra
LIB 		=
NAME 		=	rush-02
SRC 		= 	game.c main.c struct.c
HEADER 		=	$(addprefix includes/, bot.h)
OBJ 		=	$(SRC:.c=.o)
COM_STRING 	=	"Compiling"
COM_COLOR   =	\033[0;34
NO_COLOR    =	\033[m
OBJ_COLOR   =	\033[0;36m


all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) -o $(NAME) $(LIB) $(OBJ) -lm
	@printf "%b" "\033[0;32m $(NAME) is done !$(NO_COLOR)\n"

%.o: %.c $(HEADER)
	@printf "%b" "\033c";
	@printf "%b" "$(COM_STRING) $(OBJ_COLOR)$(@)$(NO_COLOR)\n";
	$(GCC) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@printf "%b" "\033[0;32m clean $(NAME)$(NO_COLOR)\n"

fclean:
	@rm -f $(NAME) $(OBJ)
	@printf "%b" "\033[0;32m fclean $(NAME)$(NO_COLOR)\n"

re: fclean all