#include "ft_printf.h"

int	ft_len_nb_uns(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int ft_print_spaces_uns(int len, t_data *flags)
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

int	ft_print_zeros_uns(int len, t_data *flags, unsigned int nb)
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

int	ft_mod_uns(unsigned int a, unsigned int b)
{
	int	r;

	r = a % (int)b;
	if (r < 0)
		return ((int)(10 - r - (int)b));
	else
		return (r);
}

int	ft_putnbr_uns(unsigned int nb, t_data *flags)
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
		str[i--] = ft_mod_uns(nb, 10) + '0';
		nb /= 10;
	}
	i++;
	out += write(STDOUT_FILENO, &str[i], 17 - i);
	return (out);
}

int	ft_print_unsigned(unsigned int nb, t_data *flags)
{
	int	out;

	out = 0;
	if (flags->dot >= 0)
		flags->zero = 0;
	if (flags->dot == -1)
		flags->dot = 1;
	if (nb == 0 && flags->dot == 0 )
		return (ft_print_x_char(flags->width, ' '));
	if (nb == 0)
		out += ft_print_spaces_uns(1, flags);
	else
		out += ft_print_spaces_uns(ft_len_nb_uns(nb), flags);
	if (nb == 0)
		out += ft_print_zeros_uns(1, flags, nb);
	else
		out += ft_print_zeros_uns(ft_len_nb_uns(nb), flags, nb);
	out += ft_putnbr_uns(nb, flags);
	out += ft_left_justify(out, flags);
	return (out);
}

//000000000000000000X0000000
//00000000000000000X0000000
//
//00000000000000000080000000
//0000000000000000080000000