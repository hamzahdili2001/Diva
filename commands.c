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
		.command = "tokens",
		.desc = "just a test",
		.function = show_tokens,
	},
	{
		.command = "playlist",
		.desc = "show playlist by index",
		.function = ft_playlist,
	},

	{
		.command = NULL,
		.desc = NULL,
		.function = NULL,
	},
};

void	ft_playlists(char **args)
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

void	ft_playlist(char **args)
{
	DIR				*dir;
	struct dirent	*entry;
	int				i;
	int				request;
	char			*extention;

	if (!*args)
		return ;
	request = ft_atoi(*args);
	if (request <= 0)
	{
		ft_putstr("Invalid Number\n");
		return ;
	}
	dir = opendir("playlists");
	if (!dir)
		return ;
	entry = readdir(dir);
	i = 1;
	while (entry)
	{
		extention = ft_strrchr(entry->d_name, '.');
		if (extention)
		{
			if (ft_strcmp(extention, ".playlist") == 0)
			{
				if (request == i)
				{
					show_playlist(entry->d_name);
					closedir(dir);
					return ;
				}
				i++;
			}
		}
		entry = readdir(dir);
	}
	closedir(dir);
}

void	ft_exit(char **args)
{
	(void)args;
	exit(0);
}

void	ft_help(char **args)
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

void	show_tokens(char **tokens)
{
	while (*tokens)
	{
		ft_putstr(*tokens);
		ft_putchar('\n');
		tokens++;
	}
}

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
			table->function(&tokens[1]);
			free_arr(tokens);
			return ;
		}
		table++;
	}
	free_arr(tokens);
	ft_putstr("\nCommand not found.\n");
}
