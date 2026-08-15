#ifndef DIVA_H
# define DIVA_H

# define TRUE 1
# define FALSE 0

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

void		ft_putchar(char c);
void		ft_putstr(char *str);
int			ft_scan(char *buffer);
int			ft_strcmp(char *s1, char *s2);
void		display_logo(void);

typedef struct s_comands
{
	char	key;
	char	*desc;
	void	(*function)(void);

}			t_comands;
#endif
