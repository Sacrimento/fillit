/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:54:42 by abouvero          #+#    #+#             */
/*   Updated: 2017/11/30 17:00:41 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		valid_char(char c)
{
	if (c == '.' || c == '#' || c == '\n')
		return (1);
	return (0);
}

static char		*is_block_valid(char *block, int i, int nl)
{
	int		diese;
	int		point;

	diese = 0;
	point = 0;
	while (block[i] && valid_char(block[i]))
	{
		if (block[i] == '\n')
			nl++;
		else if (block[i] == '#')
		{
			if (block[i + 1] == '#' || block[i - 1] == '#' ||
			block[i + 5] == '#' || block[i - 5] == '#')
				diese++;
			else
				error();
		}
		else if (block[i] == '.')
			point++;
		i++;
	}
	if (nl == 4 && diese == 4 && point == 12)
		return (block_parser(block));
	error();
	return (NULL);
}

t_list			*is_file_valid(char *file)
{
	int		i;
	int		nl;
	t_list	*list;

	i = 0;
	nl = 0;
	list = NULL;
	while (file[i])
	{
		if (!(valid_char(file[i])) || (nl == 4 && (file[i] != '\n' || !file[i])))
			error();
		if (file[i] == '\n')
			nl++;
		else if (i == 0 || nl == 5)
		{
			list = ft_list_push_back(is_block_valid(
				ft_strsub(file, i, 20), 0, 0), list);
			nl = 0;
		}
		i++;
	}
	if (!file[0] || (file[i - 1] == '\n' && file[i - 2] == '\n'))
		error();
	return (list);
}
