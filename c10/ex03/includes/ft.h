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
	int				hasOption;
	int				firstFileIdx;
	int				lastFileIdx;
	int				readFromStdin;
	char			**argv;
	unsigned char	*save;
	int				wildcardWritten;
}t_config;
void		exception_handler(char *filename, char *binary_name);
void		check_bad_file_descriptor(t_config conf);
t_config	argparser(int argc, char **argv);
void		ft_hexdump_stdin(t_config *conf, int *index);
int			ft_strcmp(char *s1, char *s2);
void		ft_putstr(char *str, int fd);
void		flush_buffer(t_config conf, unsigned char *line, int length,
				int *index);
int			get_next_valid_file(int	*currentFile, t_config conf, int *fd);
void		ft_putchar(char c, int fd);
int			ft_strlen(char *str);
int			is_last_file(int fileIndex, t_config conf);
int			ft_strncmp(unsigned char *s1, unsigned char *s2);
int			check_save(t_config *conf, unsigned char *str, int *index);
void		ft_init(t_config conf, char buffer[2], char line[16]);
void		ft_strncat(unsigned char *dest, unsigned char *src, int n);
void		ft_print_address(unsigned long int addr, t_config conf);
void		ft_print_values(unsigned char *addr, int offset, t_config conf);
void		ft_print_chars(unsigned char *addr, int offset);
void		reset_string(unsigned char *str);
char		*ft_strdup(char *src);
void		ft_strncopy(unsigned char *dst, unsigned char *src, int n);
void		ft_hexdump(t_config *conf);
void		print_line(t_config conf, unsigned char line[16], int length,
				 int *index);
#endif