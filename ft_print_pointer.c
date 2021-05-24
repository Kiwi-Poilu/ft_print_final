#include "ft_printf.h"

int	ft_lenadr(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (3);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i + 2);
}

int	ft_putadr(unsigned long long n)
{
	int		i;
	int		ret;
	char	*hex;
	char	str[17];

	i = 0;
	ret = 0;
	hex = "0123456789abcdef";
	if (n == 0)
	{
		ret += ft_putchar('0');
		return (ret);
	}
	while (n > 0)
	{
		str[i] = hex[n % 16];
		n /= 16;
		i++;
	}
	ret += i;
	while (--i >= 0)
		ft_putchar(str[i]);
	return (ret);
}

int	ft_print_pointer(unsigned long long nb, t_data *flags)
{
	int	out;

	out = 0;
	if (flags->dot != -1)
		flags->width++;
	if (flags->width > 0 && flags->dash == 0)
		out += ft_print_x_char(flags->width - ft_lenadr(nb), ' ');
	out += ft_putstr("0x", -1);
	if (flags->dot != 0)
		out += ft_putadr(nb);
	if (flags->width > 0 && flags-> dash == 1)
		out += ft_print_x_char(flags->width - ft_lenadr(nb), ' ');
	flags->dot++;
	return (out);
}
