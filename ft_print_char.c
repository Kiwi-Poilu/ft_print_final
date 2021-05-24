#include "ft_printf.h"

int	ft_print_char(int c, t_data *flags)
{
	int	out;

	out = 0;
	if (flags->dash == 0)
		out += ft_print_x_char(flags->width - 1, ' ');
	out += write(1, &c, 1);
	if (flags->dash == 1)
		out += ft_print_x_char(flags->width - 1, ' ');
	return (out);
}
