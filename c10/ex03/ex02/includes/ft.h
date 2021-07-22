#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <fcntl.h>
# include <libgen.h>
# include <sys/errno.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define STDIN 0
# define STDOUT 1
# define STDERR 2
typedef struct config{
	int	givenValue;
	int	firstFileIdx;
	int	readFromStdin;
}t_config;
int			ft_strlen(char *str);
void		ft_putchar(char c, int fd);
void		ft_putstr(char *str, int fd);
void		exception_handler(char *filename, char *binary_name);
int			ft_strcmp(char *s1, char *s2);
int			ft_atoi(char *str);
void		ft_tail(int count, int fd);
char		*ft_strncat_malloc(char *dest, char *src, int n);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
void		file_headers(char *filename, int argc, int firstFileIdx, int idx);
t_config	argparser(int argc, char **argv);
#endif