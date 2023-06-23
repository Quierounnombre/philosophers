NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=thread
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

FILES_PHILO = 	Affinius \
				diogenes \
				Tales_de_mileto \
				plato \
				Heraclito \
				kant \
				pitagoras \
				schopenhauer \

DIR_PHILO = ./
SRCS_PHILO = $(addprefix $(DIR_PHILO), $(addsuffix .c, $(FILES_PHILO)))
OBJS_PHILO = $(addprefix $(DIR_PHILO), $(addsuffix .o, $(FILES_PHILO)))

FILES_UTILS =	ft_atoi \
				ft_itoa \
				ft_strdup \
				ft_strlen \
				print_error_msg \
				ft_log \

DIR_UTILS = ./Utils/
SRCS_UTILS = $(addprefix $(DIR_UTILS), $(addsuffix .c, $(FILES_UTILS)))
OBJS_UTILS = $(addprefix $(DIR_UTILS), $(addsuffix .o, $(FILES_UTILS)))

FILES_ACTIONS =	ft_eat \
				ft_parlor_whit_dead \
				ft_sleep \
				ft_think \

DIR_ACTIONS = ./Actions/
SRCS_ACTIONS = $(addprefix $(DIR_ACTIONS), $(addsuffix .c, $(FILES_ACTIONS)))
OBJS_ACTIONS = $(addprefix $(DIR_ACTIONS), $(addsuffix .o, $(FILES_ACTIONS)))

SRCS = $(SRCS_PHILO) $(SRCS_UTILS) $(SRCS_ACTIONS)
OBJS = $(OBJS_PHILO) $(OBJS_UTILS) $(OBJS_ACTIONS)

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