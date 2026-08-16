#include "diva.h"

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}
int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (is_space(*str))
		str++;
	if (is_sign(*str) && is_num(*(str + 1)))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (is_num(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
