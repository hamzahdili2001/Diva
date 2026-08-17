#include "diva.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

size_t	get_filesize(char *file)
{
	char	byte;
	int		fd;
	size_t	length;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	length = 0;
	while (read(fd, &byte, 1))
		length++;
	close(fd);
	return (length);
}

void	display_logo(void)
{
	char	*buffer;
	char	*file;
	size_t	filesize;
	int		fd;
	ssize_t	readfile;

	file = "logo";
	filesize = get_filesize(file);
	buffer = malloc((filesize * sizeof(char)) + 1);
	if (!buffer)
		return ;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	readfile = read(fd, buffer, filesize);
	if (readfile == -1)
	{
		close(fd);
		return ;
	}
	buffer[readfile] = '\0';
	ft_putstr("\n\n");
	ft_putstr(buffer);
	ft_putstr("\n\n");
	free(buffer);
	close(fd);
}

char	*read_line(int fd)
{
	size_t	size;
	size_t	capacity;
	ssize_t	reading;
	char	*line;
	char	*temp;
	char	c;

	size = 0;
	capacity = 16;
	line = malloc(capacity);
	if (!line)
		return (NULL);
	reading = read(fd, &c, 1);
	while (reading > 0)
	{
		if (c == '\n')
			break ;
		if (size == capacity)
		{
			capacity *= 2;
			temp = realloc(line, capacity);
			if (!temp)
			{
				free(line);
				return (NULL);
			}
			line = temp;
		}
		line[size] = c;
		size++;
		reading = read(fd, &c, 1);
	}
	line[size] = '\0';
	if ((size == 0 && reading == 0) || reading == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

void	show_playlist(char *playlist)
{
	int		fd;
	int		index;
	char	*line;
	char	path[128] = "playlists/";

	ft_strcat(path, playlist);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ;
	line = read_line(fd);
	if (!line)
		return ;
	index = 1;
	while (line)
	{
		ft_putchar('[');
		ft_putnbr(index);
		ft_putstr("] ");
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
		index++;
		line = read_line(fd);
	}
}
