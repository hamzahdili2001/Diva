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

void	ft_playlists(char *args)
{
	DIR				*dir;
	struct dirent	*entry;
	char			*extension;
	char			*filename;
	int				index;

	(void)args;
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

void	ft_exit(char *args)
{
	(void)args;
	exit(0);
}

void	ft_help(char *args)
{
	const t_commands	*table;

	(void)args;
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

// TODO: function should take arr of args not one str.
// TODO: that tokens[0] need to be implemented.
void	check_input(char *input)
{
	const t_commands	*table;
	char				**tokens;

	tokens = ft_split(input);
	table = g_table;
	while (table->command)
	{
		if (ft_strcmp(tokens[0], table->command) == 0)
		{
			table->function(tokens[0]);
			free_arr(tokens);
			return ;
		}
		table++;
	}
	free_arr(tokens);
	ft_putstr("\nCommand not found.\n");
}
