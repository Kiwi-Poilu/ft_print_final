#include "ft_printf.h"

int	ft_putstr(char *str, int trunc)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (trunc >= 0)
	{
		while (str[i] && i < trunc)
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_print_string(char *str, t_data *flags)
{
	int	out;
	int	spaces;

	out = 0;
	if (str == NULL)
		str = "(null)";
	if (flags->dot >= 0 && flags->dot < (int)ft_strlen(str))
		spaces = flags->width - flags->dot;
	else
		spaces = flags->width - ft_strlen(str);
	if (flags->dash == 0)
	{
		if (flags->zero == 1)
			out += ft_print_x_char(spaces, '0');
		else
			out += ft_print_x_char(spaces, ' ');
	}
	out += ft_putstr(str, flags->dot);
	if (flags->dash == 1)
		out += ft_print_x_char(spaces, ' ');
	return (out);
}
