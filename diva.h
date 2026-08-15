#ifndef DIVA_H
# define DIVA_H

# define TRUE 1
# define FALSE 0

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		display_logo(void);
void		check_input(char *input);
int			ft_scan(char *buffer);
int			ft_strcmp(char *s1, char *s2);

// commands:
void		ft_help(void);
void		ft_exit(void);
typedef struct s_commands
{
	char	*command;
	char	*desc;
	void	(*function)(void);

}			t_commands;
#endif
