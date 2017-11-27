/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcreator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:36:04 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/27 15:22:24 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **ft_tabcreator(int size)
{
	int count;
	char *line;
	char **grid;

	count = 0;
	grid = ft_memalloc(size + 1);
	while (count < size)
	{
		if ((line = ft_strnew(size)) && grid)
			ft_memset(line, '.', size);
		grid[count] = line;
		count++;
	}
	return (grid);
}

