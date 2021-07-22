SRCS	= main.c ft_display_file.c

NAME	= ft_display_file

OBJS	=  ${SRCS:.c=.o}

.c.o	:
		gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
		gcc -Wall -Wextra -Werror ${OBJS} -o ${NAME}

all : ${NAME}


clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all
