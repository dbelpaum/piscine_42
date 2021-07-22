# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 11:06:39 by ctchen            #+#    #+#              #
#    Updated: 2021/07/18 20:15:17 by tbrowang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c					\
			libft.c					\
			ft_file_to_list.c		\
			ft_process_file.c		\
			ft_strncat_malloc.c		\
			ft_split.c				\
			ft_strjoin.c			\
			liblist.c				\
			build_string.c			\
			ft_words_list.c			\
			ft_strcmp.c				\
			ft_strndup.c			\
			ft_strndup_rev.c		\
			ft_strcat.c				\
			ft_listjoin.c			\
			ft_atoi.c				\


OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

CC		= cc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -g3

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
