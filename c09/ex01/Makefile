SRCS	= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

NAME	= libft.a

OBJS	=  ${SRCS:.c=.o}

HEADERS	= includes/

.c.o	:
		gcc -Wall -Wextra -Werror -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
		ar rc ${NAME} ${OBJS}

all : ${NAME}


clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all