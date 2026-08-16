#ifndef DIVA_H
# define DIVA_H

# define TRUE 1
# define FALSE 0

# include <dirent.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_strlen(char *str);
int			is_space(char c);
void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(long nbr);
char		*ft_strrchr(char *s, int c);
char		*ft_strndup(char *str, int n);
char		**ft_split(char *input);
void		display_logo(void);
void		free_arr(char **arr);
void		check_input(char *input);
int			ft_scan(char *buffer);
int			ft_strcmp(char *s1, char *s2);
int			ft_atoi(char *str);

// commands:
void		ft_help(char **args);
void		ft_exit(char **args);
void		ft_playlists(char **args);
void		ft_playlist(char **args);

// test
void		show_tokens(char **tokens);
typedef struct s_commands
{
	char	*command;
	char	*desc;
	void	(*function)(char **args);

}			t_commands;
#endif
