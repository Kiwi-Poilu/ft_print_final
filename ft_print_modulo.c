#include "ft_printf.h"

int	ft_print_modulo(t_data *flags)
{
	int	out;

	out = 0;
	if (flags->dash == 0)
	{
		if (flags->zero == 1)
			out += ft_print_x_char(flags->width - 1, '0');
		else
			out += ft_print_x_char(flags->width - 1, ' ');
	}
	out += ft_putchar('%');
	if (flags->dash == 1)
		out += ft_print_x_char(flags->width - 1, ' ');
	return (out);
}
