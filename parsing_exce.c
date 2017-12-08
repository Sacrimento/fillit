/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_exce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 12:22:32 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/08 12:27:42 by mfonteni         ###   ########.fr       */
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

char			*exce_parsing(char *block)
{
	char	*parsed;

	parsed = remove_nl(block);
	if (ft_strstr(parsed, "##..#...#"))
		parsed = "rbdd";
	else if (ft_strstr(parsed, "###.#"))
		parsed = "dbrr";
	else
		parsed = NULL;
	return (parsed);
}
