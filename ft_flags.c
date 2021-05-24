#include "ft_printf.h"

int	ft_len_nb(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_width(const char *format, int *i, va_list args, t_data *flags)
{
	if (format[*i] == '*')
	{
		flags->width = va_arg(args, int);
		if (flags->width < 0)
		{
			flags->width *= -1;
			flags->dash = 1;
		}
		(*i)++;
	}
	else
	{
		flags->width = ft_atoi((char *)format + *i);
		(*i) += ft_len_nb(flags->width);
	}
}

void	ft_dot(const char *format, int *i, va_list args, t_data *flags)
{
	if (ft_is_digit(format[(*i) + 1]) || format[(*i) + 1] == '*')
		(*i)++;
	if (format[*i] == '*')
	{
		flags->dot = va_arg(args, int);
		if (flags->dot < 0 )
		{
			flags->dot = -1;
		}
		(*i)++;
	}
	else
	{
		flags->dot = ft_atoi((char *)format + *i);
		while (format[*i] >= '0' && format[*i] <= '9')
			++(*i);
	}
	if (format[*i] == '.')
		++(*i);
}

void	ft_init_flags(t_data *flags)
{
	flags->dash = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->star = 0;
	flags->dot = -1;
	flags->width = 0;
}

void	ft_fill_flags(const char *format, int *i, va_list args, t_data *flags)
{
	ft_init_flags(flags);
	while ((ft_is_flag(format[*i]) || ft_is_digit
			(format[*i])))
	{
		if (format[*i] == '-')
			ft_dash(i, flags);
		if (format[*i] == '+')
			ft_plus(i, flags);
		if (format[*i] == ' ')
			ft_space(i, flags);
		if (format[*i] == '0')
			ft_zero(i, flags);
		if (ft_is_digit(format[*i]) || format[*i] == '*')
			ft_width(format, i, args, flags);
		if (format[*i] == '.')
			ft_dot(format, i, args, flags);
	}
}
