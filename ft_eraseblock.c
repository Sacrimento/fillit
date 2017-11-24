/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eraseblock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:49:05 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/24 11:55:23 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_eraseblock(char **grid, char c)
{
	int line;
	int row;
	int count;

	line = 0;
	row = 0;
	count = 0;
	while (grid[line] && count <= 4)
	{
		while (grid[line][row])
		{
			if (grid[line][row] == c)
			{
				grid[line][row] = '.';
				count++;
			}
			row++;
		}
		row = 0;
		line++;
	}
}
