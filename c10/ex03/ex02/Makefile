SRCS	= main.c ft_tail.c libft.c libft2.c

NAME	= ft_tail

OBJS	=  ${SRCS:.c=.o}

HEADERS	= includes/

.c.o	:
		gcc -Wall -Wextra -Werror -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
		gcc -Wall -Wextra -Werror -I ${HEADERS} ${OBJS} -o ${NAME}

all : ${NAME}


clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all