/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:05:28 by abouvero          #+#    #+#             */
/*   Updated: 2017/11/24 15:08:00 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void  ft_tab_swap(int **tab, int **bin)
{
	int i;
	int tmp;

	i = 0;
	while ((*bin)[i] == 1)
		i++;
	i -= 1;
	tmp = (*tab)[i];
	(*tab)[i] = (*tab)[i + 1];
	(*tab)[i + 1] = tmp;
}

int		check_tab_values(int **bin, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if ((*bin)[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

void	fill_tabs(int **tab, int **bin, int nbr)
{
	int		i;

	i = 0;
	while (i < nbr)
	{
		(*tab)[i] = i;
		(*bin)[i] = 0;
		i++;
	}
}

int ft_block_well_placed(int *tab, int nbr)
{
	(void)tab;
	(void)nbr;
	return (0);
}

void	ft_comb(int nbr)
{
	int		*tab;
	int		*bin;
	int		i;
	int		ret;

	i = 0;
	tab = (int*)malloc(sizeof(int) * (nbr - 1));
	bin = (int*)malloc(sizeof(int) * (nbr - 1));
	fill_tabs(&tab, &bin, nbr);
	while (!(check_tab_values(&bin, nbr)))
	{
		if ((ret = ft_block_well_placed(tab, nbr)))
		{
			bin[ret] = 0;
			ft_tab_swap(&tab, &bin);
		}
		else
			bin[i++] = 1;
	}
}

int main(int argc, char const *argv[]) {
	(void)argc;
	printf("TEST3");
	ft_comb(atoi(argv[1]));
	printf("TEST2");
	return 0;
}
