#include "diva.h"
#include <fcntl.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	count_words(char *str)
{
	int	words;
	int	in_word;

	words = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_space(*str))
		{
			if (!in_word)
			{
				words++;
				in_word = 1;
			}
		}
		else
		{
			in_word = 0;
		}
		str++;
	}
	return (words);
}

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*string;

	string = malloc((sizeof(char) * n) + 1);
	if (!string)
		return (NULL);
	i = 0;
	while (i < n)
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

// simple splite by space to test.
// TODO: make an actual ft_split using charset.
char	**ft_split(char *input)
{
	char	**arr;
	char	*start;
	char	*end;
	int		index;

	arr = malloc(sizeof(char *) * (count_words(input) + 1));
	if (!arr)
		return (NULL);
	index = 0;
	while (index < count_words(input))
	{
		while (*input && is_space(*input))
			input++;
		start = input;
		end = start;
		while (*end && !is_space(*end))
			end++;
		arr[index] = ft_strndup(start, end - start);
		input = end;
		index++;
	}
	arr[index] = NULL;
	return (arr);
}

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
