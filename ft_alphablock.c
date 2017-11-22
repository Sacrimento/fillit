/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alphablock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:45:54 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/22 15:55:45 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_alphablock(char c, char **grid)
{
	int countl;
	int countr;
	int counthash;

	countl = 0;
	countr = 0;
	counthash = 0;
	while (grid[countl])
	{
		while (grid[countl][countr])
		{
			if (grid[countl][countr] == '#')
			{
				grid[countl][countr++] = c;
				counthash++;
			}
		}
		countr = 0;
		countl++;
	}
	if (counthash == 4)
		return (1);
	return (0);
}
