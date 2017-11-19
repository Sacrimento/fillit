/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:54:42 by abouvero          #+#    #+#             */
/*   Updated: 2017/11/18 12:17:57 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		valid_char(char c)
{
	if (c == '.' || c == '#' || c == '\n')
		return (1);
	return (0);
}

static void is_block_valid(char *block)
{
	int		diese;
	int		point;
	int		nl;
	int		i;

	diese = 0;
	point = 0;
	nl = 0;
	i = 0;
	while (block[i] && valid_char(block[i]))
	{
		if (block[i] == '\n')
			nl++;
		else if (block[i] == '#')
		{
			if (block[i + 1] == '#' || block[i - 1] == '#' || block[i + 5] == '#' ||
						block[i - 5] == '#')
				diese++;
			else
				error();
		}
		else if (block[i] == '.')
			point++;
		i++;
	}
	if (nl == 4 && diese == 4 && point == 12)
	{
		block_parser(block);
		return ;
	}
	error();
}

int		is_file_valid(char *file)
{
	int		i;
	int		nl;

	i = 0;
	nl = 0;
	while (file[i] && valid_char(file[i]))
	{
		if (file[i] == '\n')
			nl++;
		else if (i == 0 || nl == 5)
		{
			is_block_valid(ft_strsub(file, i, 20));
			nl = 0;
		}
		i++;
	}
	return (1);
}
