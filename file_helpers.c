#include "diva.h"

size_t	get_filesize(char *file)
{
	char	byte;
	int		fd;
	size_t	length;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
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
