/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alphablock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:45:54 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/29 18:27:51 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	alphablock(char **grid, char letter)
{
	int line;
	int row;
	int counthash;

	line = 0;
	row = 0;
	counthash = 0;
	while (grid[line] && counthash < 4)
	{
		while (grid[line][row])
		{
			if (grid[line][row] == '#')
			{
				grid[line][row] = letter;
				counthash++;
			}
			row++;
		}
		row = 0;
		line++;
	}
	return (1);
}
