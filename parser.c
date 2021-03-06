/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 10:55:06 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/08 13:41:54 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_charchr(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int		get_i(int i, int dir, char *parsed, int diese)
{
	if (dir == 5)
		parsed[diese] = 'd';
	else if (dir == -1)
		parsed[diese] = 'l';
	else if (dir == 1)
		parsed[diese] = 'r';
	else if (dir == -5)
		parsed[diese] = 'u';
	else if (dir == 0)
	{
		parsed[diese] = 'b';
		return (0);
	}
	return (i + dir);
}

static int		get_topleft(char **tab)
{
	int		i;
	int		j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tab[i][j] == '#')
				return ((i + 1) * 5 - (4 - j) - 1);
			i++;
		}
		j++;
	}
	return (0);
}

static int		back_parser(char *block, int *coo, char *parsed, int diese)
{
	if (!ft_charchr(block, '#'))
		return (0);
	parsed[diese] = 'b';
	return (coo[diese - 1]);
}

char			*block_parser(char *b)
{
	int		i;
	int		diese;
	int		coo[4];
	char	*parsed;

	if ((parsed = exce_parsing(b)))
		return (parsed);
	parsed = ft_strnew(4);
	i = get_topleft(ft_strsplit(b, '\n'));
	diese = -1;
	while (++diese < 4 && (b[i] = '.'))
	{
		coo[diese] = i;
		if (b[i + 5] == '#')
			i = get_i(i, 5, parsed, diese);
		else if (b[i - 1] == '#')
			i = get_i(i, -1, parsed, diese);
		else if (b[i + 1] == '#')
			i = get_i(i, 1, parsed, diese);
		else if (b[i - 5] == '#')
			i = get_i(i, -5, parsed, diese);
		else if (!(i = back_parser(b, coo, parsed, diese)))
			return (parsed);
	}
	return (parsed);
}
