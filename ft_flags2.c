#include "ft_printf.h"

void	ft_dash(int *i, t_data *flags)
{
	flags->dash = 1;
	(*i)++;
}

void	ft_plus(int *i, t_data *flags)
{
	flags->plus = 1;
	(*i)++;
}

void	ft_space(int *i, t_data *flags)
{
	flags->space = 1;
	(*i)++;
}

void	ft_zero(int *i, t_data *flags)
{
	flags->zero = 1;
	(*i)++;
}

int	ft_is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '*' || c == '.')
		return (1);
	return (0);
}
