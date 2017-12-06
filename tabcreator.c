/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabcreator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:45:31 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/06 14:45:33 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**tabcreator(int size)
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
