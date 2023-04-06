NAME = philo
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
src = philo.c\
		philo_utils.c\
		arguments_check.c\
		philo_utils_1.c\
		message.c\
		actions.c\

OBJECTS = ${src:.c=.o}

all	:	$(NAME)

$(NAME):	$(OBJECTS)
	$(CC) $(CFLAGS) -pthread $(OBJECTS) -o $(NAME)
		
clean :
	$(RM) $(OBJECTS)
fclean : clean
	$(RM) $(NAME)
re : fclean all
.PHONY: all clean fclean re