/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alphablock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:45:54 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/29 18:27:51 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_alphablock(char **grid, char c)
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
				grid[line][row] = c;
				counthash++;
			}
			row++;
		}
		row = 0;
		line++;
	}
}
