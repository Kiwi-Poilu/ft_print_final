#include "ft_printf.h"

int	ft_len_hex(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	ft_print_zeros_hex(int len, t_data *flags, int nb)
{
	int	zeros;
	int	out;

	zeros = 0;
	out = 0;
	if (flags->dot > len)
		zeros = flags->dot - len;
	if (flags->dot > len && nb < 0)
		zeros++;
	while (zeros-- > 0)
		out += ft_putchar('0');
	return (out);
}

int	ft_puthex(unsigned int n, char c)
{
	int		i;
	int		ret;
	char	*hex;
	char	str[8];

	i = 0;
	if (c == 'x')
		hex = "0123456789abcdef";
	else if (c == 'X')
		hex = "0123456789ABCDEF";
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		str[i] = hex[n % 16];
		n /= 16;
		i++;
	}
	ret = i;
	while (--i >= 0)
		ft_putchar(str[i]);
	return (ret);
}

int	ft_print_hex(unsigned int nb, t_data *flags, char c)
{
	int	out;

	out = 0;
	if (flags->dot > 0)
		flags->zero = 0;
	if (flags->dot == -1)
		flags->dot = 1;
	if (nb == 0 && flags->dot == 0 )
		return (ft_print_x_char(flags->width, ' '));
	if (nb == 0)
		out += ft_print_spaces(1, flags, nb);
	else
		out += ft_print_spaces(ft_len_hex(nb), flags, nb);
	if ((nb < 0) && flags->zero == 0)
		out += ft_putchar('-');
	if (nb == 0)
		out += ft_print_zeros_hex(1, flags, nb);
	else
		out += ft_print_zeros_hex(ft_len_hex(nb), flags, nb);
	out += ft_puthex(nb, c);
	out += ft_left_justify(out, flags);
	return (out);
}
