/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcreator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:36:04 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/04 13:36:59 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_tabcreator(int size)
{
	int		count;
	char	*line;
	char	**grid;

	count = 0;
	if (!(grid = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	while (count < size)
	{
		if ((line = ft_strnew(size)) && grid)
		{
			ft_memset(line, '.', size);
			grid[count] = line;
		}
		count++;
	}
	grid[count] = 0;
	return (grid);
}
