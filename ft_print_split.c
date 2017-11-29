#include "libft/libft.h"

void	ft_print_split(char **tab, int limit)
{
	int line;
	int row;

	line = 0;
	row = 0;
	while (line < limit)
	{
		while (row < limit)
		{
			ft_putchar(tab[line][row++]);
			ft_putchar('\n');
		}
		line++;
		row = 0;
	}
}
