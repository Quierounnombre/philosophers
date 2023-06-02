NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

BLACK = \033[0;30m
RED =   \033[0;31m
GREEN = \033[0;32m
YELLOW =    \033[0;33m
BLUE  = \033[0;34m
MAGENTA =   \033[0;35m
CYAN =  \033[0;36m
LGRAY = \033[0;37m
DGRAY = \033[1;30m
LBLUE = \033[1;34m
LGREEN = \033[1;32m
LCYAN = \033[1;36m
LRED = \033[1;31m
LMAGENTA =\033[1;35m
LYELLOW = \033[1;33m
WHITE = \033[1;37m
RESET = \033[0m

FILES = Affinius \
		diogenes \
		Tales_de_mileto \

DIR = ./
SRCS = $(addprefix $(DIR), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(DIR), $(addsuffix .o, $(FILES)))

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "$(GREEN)\n$(NAME) compilado\n$(RESET)" 

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@echo "$(YELLOW)\nArchivos .o limpiados\n$(RESET)"

fclean: clean
	@$(RM) $(NAME) 
	@echo "$(RED)\n$(NAME) limpiada\n$(RESET)"

re: fclean all

do_clean:	all clean

.PHONY: all clean fclean re libft do_clean
.SILENT: