/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:24:28 by abouvero          #+#    #+#             */
/*   Updated: 2017/11/30 11:24:35 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_print_split(char **tab, int limit)
{
	int line;
	int row;

	line = 0;
	row = 0;
	while (line < limit)
	{
		while (row < limit)
		{
			ft_putchar(tab[line][row++]);
			ft_putchar('\n');
		}
		line++;
		row = 0;
	}
}
