#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <fcntl.h>
# include <libgen.h>
# include <sys/errno.h>
# include <stdio.h>
# include <string.h>
int		ft_strlen(char *str);
void	ft_putchar(char c, int fd);
void	ft_putstr(char *str, int fd);
void	exception_handler(char *filename, char *binary_name);
void	display_file(int fd);
#endif