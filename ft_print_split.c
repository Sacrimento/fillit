#include "libft/libft.h"

void	ft_print_split(char **tab)
{
	int cursor;

	cursor = 0;
	while (tab[cursor] != 0)
	{
		ft_putstr(tab[cursor]);
		ft_putchar('\n');
		cursor++;
	}
}
