#include "diva.h"

static const t_commands	g_table[] = {{
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
											.command = NULL,
											.desc = NULL,
											.function = NULL,
										}};

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
