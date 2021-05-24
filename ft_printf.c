#include "ft_printf.h"

int 	ft_treat(const char *format, int *i, va_list args)
{
	int		out;
	t_data	flags;

	out = 0;
	ft_fill_flags(format, i, args, &flags);
	if (format[*i] == '%')
		out += ft_print_modulo(&flags);
	else if (format[*i] == 'c')
		out += ft_print_char(va_arg(args, int), &flags);
	else if (format[*i] == 's')
		out += ft_print_string(va_arg(args, char *), &flags);
	else if (format[*i] == 'p')
		out += ft_print_pointer(va_arg(args, unsigned long long), & flags);
	else if (format[*i] == 'd' || format[*i] == 'i')
		out += ft_print_nb(va_arg(args, int), &flags);
	else if (format[*i] == 'u')
		out += ft_print_unsigned(va_arg(args, unsigned int), &flags);
	else if (format[*i] == 'x' || format[*i] == 'X')
		out += ft_print_hex(va_arg(args, unsigned int), &flags, format[*i]);
	(*i)++;
	return (out);
}

int 	ft_printf(const char *format, ...)
{
	int		i;
	int		out;
	va_list	args;

	i = 0;
	out = 0;
	va_start(args, format);
	while (i < ft_strlen((char *)format) && format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			out += ft_treat(format, &i, args);
		}
		else
			out += ft_putchar(format[i++]);
	}
	va_end(args);
	return (out);
}
