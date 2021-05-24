#include "ft_printf.h"

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_print_x_char(int len, char c)
{
	int	count;

	count = len;
	while (len > 0)
	{
		ft_putchar(c);
		len--;
	}
	if (count > 0)
		return (count);
	else
		return (0);
}

int	ft_left_justify(int out, t_data *flags)
{
	int	tmp;

	tmp = out;
	out = 0;
	if (flags->dash == 1)
	{
		while (flags->width > tmp)
		{
			out += ft_putchar(' ');
			flags->width--;
		}
	}
	return (out);
}

int	ft_print_spaces(int len, t_data *flags, int nb)
{
	int	spaces;
	int	zeros;
	int	out;

	zeros = 0;
	spaces = 0;
	out = 0;
	if (flags->dot > len)
		zeros = flags->dot - len;
	if (flags->width > len + zeros)
	{
		if (nb < 0)
			spaces = flags->width - len - zeros - 1;
		else
			spaces = flags->width - len - zeros;
	}
	if (flags->dash == 0)
	{
		if (flags->zero == 1)
			out += ft_print_x_char(spaces, '0');
		else
			out += ft_print_x_char(spaces, ' ');
	}
	return (out);
}

int	ft_atoi(char *str)
{
	unsigned long long	nb;
	int					sign;
	int					i;

	nb = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + str[i] - 48;
		i++;
	}
	if (sign > 0)
		return (nb);
	else
		return (-nb);
}
