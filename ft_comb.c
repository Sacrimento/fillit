/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:05:28 by abouvero          #+#    #+#             */
/*   Updated: 2017/11/28 14:45:29 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_tab_swap(int *tab, int *bin, int nbr)
{
	int i;
	int tmp;

	i = 0;
	while (bin[i] == 1)
		i++;

	if (i != nbr - 1)
	{
		tmp = tab[i];
		tab[i] = tab[i + 1];
		tab[i + 1] = tmp;
		tmp = bin[i];
		bin[i] = bin[i + 1];
		bin[i + 1] = tmp;
	}

}

int		check_tab_values(int *bin, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (bin[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

void	fill_tabs(int *tab, int *bin, int nbr)
{
	int		i;

	i = 0;
	while (i < nbr)
	{
		tab[i] = i;
		bin[i] = 0;
		i++;
	}
}

void print_tab(int *tab, int size)
{
	int i = 0;
	while (i < size)
	{
		printf("[%d] ", tab[i]);
		i++;
	}
	printf("\n");
}

void	ft_comb(int nbr, t_list *list)
{
	int		*tab;
	int		*bin;
	int		i;
	char	**grid = ft_tabcreator(16);

	i = 0;
	tab = (int*)malloc(sizeof(int) * (nbr));
	bin = (int*)malloc(sizeof(int) * (nbr));
	fill_tabs(tab, bin, nbr);

	while (!(check_tab_values(bin, nbr)))
	{
		//print_tab(tab, nbr);
		//print_tab(bin, nbr);
		//printf("LISTE : %s, %c\n", (ft_list_at(list, tab[i]))->content, (ft_list_at(list, tab[i]))->letter);
		//for (int j = 0; j < 7; j++)
			//printf("%s\n", (ft_list_at(list, j)->content));
		if (!(ft_placenext((ft_list_at(list, tab[i]))->content, grid, 11, (ft_list_at(list, tab[i]))->letter)))
		{
			bin[i] = 0;
			ft_tab_swap(tab, bin, nbr);
		}
		else
			bin[i++] = 1;

		ft_print_split(grid);
		printf("\n");
	}
}
