/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combv2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:34:15 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/06 14:21:10 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	combination(t_block_sort *maintab, int start, int decal, char **grid)
{
	if (!is_blocks_left(maintab))
		return (1);
	while (start < block_tab_size(maintab) && already_set(maintab[start]))
		start++;
	if (start > block_tab_size(maintab) || !(maintab[start]).block)
		return (0);
	if (already_set(maintab[start]))
		return (0);
	if (!placenext((maintab[start]).block, grid, start + 'A', decal))
		return (combination(maintab, start + 1, 0, grid));
	else
		maintab[start] = mark_as_set(maintab[start]);
	if (combination(maintab, 0, 0, grid))
		return (1);
	else
	{
		maintab[start] = mark_as_notset(maintab[start]);
		eraseblock(grid, start + 'A');
		return (combination(maintab, start + 1, 0, grid));
	}
	return (0);
}
