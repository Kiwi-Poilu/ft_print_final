//
// Created by kiwi on 5/24/21.
//

#include "ft_printf.h"
//
//int main()
//{
//	ft_printf("%.*d\n", 3, -12);
//	printf("%.*d\n", 3, -12);
//}
//
//int main() {
//	ft_printf("%.*u\n", 5, 4294967284);
//	printf("%.*u\n", 5, 4294967284u);
//}

static int	ft_len_nb_uns(unsigned int n)
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

int main(void)
{
	printf("%d\n", ft_len_nb_uns(8));
	printf("%d\n", ft_len_nb_uns(8));
	ft_printf("%*.*x\n", 42, 25, 0x80000000);
	printf("%*.*x\n", 42, 25, 0x80000000);
}