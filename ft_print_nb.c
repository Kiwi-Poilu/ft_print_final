#include "ft_printf.h"

int	ft_print_zeros(int len, t_data *flags, int nb)
{
	int	zeros;
	int	out;

	zeros = 0;
	out = 0;
	if (flags->dot > len)
		zeros = flags->dot - len;
	if (flags->dot >= len && nb < 0)
		zeros++;
	while (zeros-- > 0)
		out += ft_putchar('0');
	return (out);
}

int	ft_save_space(int nb, t_data *flags)
{
	int	out;

	out = 0;
	if (nb == 0)
		out += ft_print_spaces(1, flags, nb);
	else
	{
		if (nb < 0)
			out += ft_print_spaces(ft_len_nb(nb) - 1, flags, nb);
		else
			out += ft_print_spaces(ft_len_nb(nb), flags, nb);
	}
	return (out);
}

int	ft_print_nb(int nb, t_data *flags)
{
	int	out;

	out = 0;
	if (flags->dot >= 0)
		flags->zero = 0;
	if (flags->dot == -1)
		flags->dot = 1;
	if (nb == 0 && flags->dot == 0 )
		return (ft_print_x_char(flags->width, ' '));
	if (nb < 0 && flags->zero == 1)
		out += ft_putchar('-');
	out += ft_save_space(nb, flags);
	if ((nb < 0) && flags->zero == 0)
		out += ft_putchar('-');
	if (nb == 0)
		out += ft_print_zeros(1, flags, nb);
	else
		out += ft_print_zeros(ft_len_nb(nb), flags, nb);
	out += ft_putnbr(nb, flags);
	out += ft_left_justify(out, flags);
	return (out);
}

int	ft_mod(int a, int b)
{
	int	r;

	r = a % (int)b;
	if (r < 0)
		return ((int) 10 - r - (int)b);
	else
		return (r);
}

int	ft_putnbr(int nb, t_data *flags)
{
	int		out;
	char	str[17];
	int		i;

	out = 0;
	if (nb == 0 && flags->dot > 0)
	{
		write(STDOUT_FILENO, "0", 1);
		return (1);
	}
	i = 16;
	while (nb != 0)
	{
		str[i--] = ft_mod(nb, 10) + '0';
		nb /= 10;
	}
	i++;
	out += write(STDOUT_FILENO, &str[i], 17 - i);
	return (out);
}
