#include "diva.h"

int	main(void)
{
	char	buffer[100];

	display_logo();
	while (TRUE)
	{
		ft_putstr("\ndiva> ");
		ft_scan(buffer);
		if (ft_strcmp(buffer, "exit") == 0)
			return (0);
		// check_input(buffer);
		ft_putstr(buffer);
		ft_putchar('\n');
	}
	return (0);
}
