/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:16:22 by abouvero          #+#    #+#             */
/*   Updated: 2017/11/30 11:20:56 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*remove_nl(char *b)
{
	int		i;
	int		j;
	char	*new_b;

	new_b = ft_strnew(ft_strlen(b));
	i = 0;
	j = 0;
	while (b[i])
	{
		if (b[i] == '\n')
			i++;
		new_b[j++] = b[i];
		i++;
	}
	return (new_b);
}

static char		*tetri_parser_exce(char *b)
{
	char	*parsed;

	parsed = remove_nl(b);
	if (ft_strstr(parsed, "###..#"))
		parsed = "rdbr";
	else if (ft_strstr(parsed, "#...##..#"))
		parsed = "urbu";
	else if (ft_strstr(parsed, "#..##...#"))
		parsed = "rubd";
	else if (ft_strstr(parsed, "#..###"))
		parsed = "rubr";
	else if (ft_strstr(parsed, "##..##"))
		parsed = "urd";
	else
		parsed = NULL;
	return (parsed);
}

static int		extreminos(char *b)
{
	int		i;
	int		expectopatrominos;
	int		last_d;

	i = 0;
	while (b[i])
	{
		expectopatrominos = 0;
		while (b[i] && b[i] != '#')
			i++;
		if (b[i + 1] == '#')
			expectopatrominos++;
		if (b[i - 1] == '#')
			expectopatrominos++;
		if (b[i + 5] == '#')
			expectopatrominos++;
		if (b[i - 5] == '#')
			expectopatrominos++;
		if (expectopatrominos == 1)
			return (i);
		else
			last_d = i++;
	}
	return (last_d);
}

static int		filler(char *b, char *parsed, int j, int code)
{
	if (*(b + 1) == '#' && code != -1)
	{
		parsed[j] = 'r';
		return (1);
	}
	else if (*(b + 5) == '#' && code != -5)
	{
		parsed[j] = 'd';
		return (5);
	}
	else if (*(b - 5) == '#' && code != 5)
	{
		parsed[j] = 'u';
		return (-5);
	}
	else if (*(b - 1) == '#' && code != 1)
	{
		parsed[j] = 'l';
		return (-1);
	}
	else
		error();
	return (0);
}

char			*block_parser(char *b)
{
	int		i;
	int		j;
	char	*parsed;
	int		code;

	code = 0;
	i = extreminos(b);
	j = 0;
	if ((parsed = tetri_parser_exce(b)))
		return (parsed);
	b = &(*(b + i));
	parsed = ft_strnew(3);
	while (j < 3)
	{
		code = filler(b, parsed, j, code);
		b = &(b[code]);
		j++;
	}
	return (parsed);
}
