#include "diva.h"
#include <fcntl.h>
#include <unistd.h>

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
			return (1);
		}
		index++;
	}
	return (0);
}
