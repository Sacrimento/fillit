/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combv2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:34:15 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/30 15:09:49 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* ft_combv2 a combinasion generator with recursive backtracking
 * ///////////////=================================================
 * maintab is a struct array with the blocks in alphabetic orderi
 * TODO :
 * trying a first lop then give the new limit as reference for another loop,
 * if the program fails with the new limits it means we got the perfect solution
 * ///////////////=================================================
 */

int	ft_combination(t_block_sort *maintab, int start, char **grid, int limit)
{
	if (!is_blocks_left(maintab))
		return (1);
	while (start < block_tab_size(maintab) && already_set(maintab[start]))
		start++;
	if (start > block_tab_size(maintab) || !(maintab[start]).block)
		return (0);
	if (already_set(maintab[start]))
		return (0);
	if (!ft_placenext((maintab[start]).block, grid, limit, start + 65))
	{
		if (start + 1 > block_tab_size(maintab))
			return (0);
		return (ft_combination(maintab, start + 1, grid, limit));
	}
	else
		maintab[start] = mark_as_set(maintab[start]);
	if (ft_combination(maintab, 0, grid, limit))
		return (1);
	else
	{
		maintab[start] = mark_as_notset(maintab[start]);
		ft_eraseblock(grid, start + 65);
		return (ft_combination(maintab, start + 1, grid, limit));
	}
	return (0);
}
