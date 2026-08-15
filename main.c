#include "diva.h"

int	main(void)
{
	char	buffer[100];

	display_logo();
	while (TRUE)
	{
		ft_putstr("\ndiva> ");
		ft_scan(buffer);
		check_input(buffer);
	}
	return (0);
}
