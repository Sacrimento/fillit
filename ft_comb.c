/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:05:28 by abouvero          #+#    #+#             */
/*   Updated: 2017/11/28 18:54:20 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_block_sort	*struct_init(t_list *list, int j)
{
	t_block_sort	*tab;
	int				i;

	tab = (t_block_sort*)malloc(sizeof(t_block_sort) * ft_list_size(list));
	i = 0;
	while (i < ft_list_size(list))
	{
		(tab[i]).numero = i;
		(tab[i]).placed = 0;
		(tab[i]).tried  = 0;
		i++;
	}
	(tab[0]).numero = j;
	(tab[j]).numero = 0;
	return (tab);
}

int		check_struct_values(t_block_sort *tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if ((tab[i]).placed == 0)
			return (0);
		i++;
	}
	return (1);
}

int		check_struct_tries(t_block_sort *tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if ((tab[i]).tried == 0)
			return (0);
		i++;
	}
	return (1);
}

void 	ft_tab_swap(t_block_sort *tab, int size)
{
	int		i;
	int		j;
	t_block_sort tmp;

	i = 0;
	while ((tab[i]).placed == 1 || (tab[i]).tried == 1)
		i++;
	j = i - 1;
	while (i < size)
	{
		if ((tab[i]).tried == 0)
		{
			tmp = tab[i];
			tab[i] = tab[j];
			tab[j]= tmp;
			return ;
		}
		i++;
	}
}

void 	ft_print_struct(t_block_sort *tab, int size)
{
	int		i = 0;
	while (i < size)
	{
		printf("[NUMERO : %d] ", (tab[i]).numero);
		printf("[PLACED : %d] ", (tab[i]).placed);
		printf("[TRIED : %d]\n", (tab[i]).tried);
		i++;
	}
}

void 	ft_clear_right(t_block_sort *tab, int size)
{
	int		i = 0;
	while (i < size)
	{
		(tab[i]).tried = 0;
		i++;
	}
}

int 	ft_check_right(t_block_sort *tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if ((tab[i]).tried == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_comb(t_list *list, int j)
{
	int		i;
	t_block_sort	*tab;
	char	**grid = ft_tabcreator(16);

	tab = struct_init(list, j);
	i = 0;
	while (!(check_struct_values(tab, ft_list_size(list))))
	{
		ft_print_struct(tab, ft_list_size(list));
		(tab[i]).tried = 1;
		if (!(ft_placenext((ft_list_at(list, (tab[i]).numero))->content, grid, 15, (ft_list_at(list, (tab[i]).numero))->letter)))
		{
			ft_tab_swap(tab, ft_list_size(list));
			if (ft_check_right(&(tab[i]), ft_list_size(list) - i))
			{
				ft_clear_right(&(tab[i]), ft_list_size(list) - i);
				i--;
			}
		}
		else
			(tab[i++]).placed = 1;
		ft_print_split(grid);
		if (check_struct_tries(tab, ft_list_size(list)))
			return (0);
	}
	return (1);
}

void 	ft_init(t_list *list)
{
	int		i;

	i = 0;
	while (i < ft_list_size(list))
	{
		if (ft_comb(list, i))
		{
			printf("SUCCESS\n");
			i = ft_list_size(list) + 12;
			return ;
		}
		i++;
		if (i == ft_list_size(list))
		{
			printf("FAILURE GROS NOOB\n");
			return;
		}
	}
}
