#include "diva.h"
#include <fcntl.h>
#include <unistd.h>

void	ft_putnbr(long nbr)
{
	char	c;

	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = (nbr % 10) + '0';
	ft_putchar(c);
}
char	*ft_strrchr(char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == c)
		{
			last = s;
		}
		s++;
	}
	return (last);
}
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 && *s2) && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_scan(char *buffer)
{
	int	index;

	index = 0;
	while (read(0, &buffer[index], 1))
	{
		if (buffer[index] == '\n')
		{
			buffer[index] = '\0';
			return (TRUE);
		}
		index++;
	}
	return (FALSE);
}
