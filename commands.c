#include "diva.h"
#include <dirent.h>

static const t_commands	g_table[] = {
	{
		.command = "help",
		.desc = "Display available commands.",
		.function = ft_help,
	},
	{
		.command = "exit",
		.desc = "Exit from the program.",
		.function = ft_exit,
	},
	{
		.command = "playlists",
		.desc = "Show existing Playlists.",
		.function = ft_playlists,

	},
	{
		.command = NULL,
		.desc = NULL,
		.function = NULL,
	},
};

void	ft_playlists(void)
{
	DIR				*dir;
	struct dirent	*entry;
	char			*extension;
	char			*filename;
	int				index;

	dir = opendir("playlists");
	if (!dir)
		return ;
	entry = readdir(dir);
	index = 1;
	while (entry)
	{
		extension = ft_strrchr(entry->d_name, '.');
		if (extension)
		{
			if (ft_strcmp(extension, ".playlist") == 0)
			{
				ft_putchar('[');
				ft_putnbr(index);
				ft_putchar(']');
				ft_putchar(' ');
				index++;
				filename = entry->d_name;
				while (filename < extension)
				{
					ft_putchar(*filename);
					filename++;
				}
				ft_putchar('\n');
			}
		}
		entry = readdir(dir);
	}
	closedir(dir);
}

void	ft_exit(void)
{
	exit(0);
}

void	ft_help(void)
{
	const t_commands	*table;

	table = g_table;
	ft_putstr("\nCOMMAND\t\tDESCRIPTION\n\n");
	while (table->command)
	{
		ft_putstr(table->command);
		ft_putstr("\t\t");
		ft_putstr(table->desc);
		ft_putchar('\n');
		table++;
	}
}

void	check_input(char *input)
{
	const t_commands	*table;

	table = g_table;
	while (table->command)
	{
		if (ft_strcmp(input, table->command) == 0)
		{
			table->function();
			return ;
		}
		table++;
	}
	ft_putstr("\nCommand not found.\n");
}
