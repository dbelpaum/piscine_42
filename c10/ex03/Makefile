SRCS	= main.c ft_hexdump.c libft.c ft_print_memory.c string.c ft_hexdump_stdin.c

NAME	= ft_hexdump

OBJS	=  ${SRCS:.c=.o}

HEADERS	= includes/

.c.o	:
		gcc -Wall -Wextra -Werror -g -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
		gcc -Wall -Wextra -Werror -g -I ${HEADERS} ${OBJS} -o ${NAME}

all : ${NAME}


clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all