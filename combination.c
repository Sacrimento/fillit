/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combv2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:34:15 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/04 19:39:36 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* combination is a combination generator with recursive backtracking
 * ///////////////=================================================
 * maintab is a struct array with the blocks in alphabetic orderi
 * TODO :
 * trying a first lop then give the new limit as reference for another loop,
 * if the program fails with the new limits it means we got the perfect solution
 * ///////////////=================================================
 */

int	combination(t_block_sort *maintab, int start, char **grid)
{
	if (!is_blocks_left(maintab))
		return (1);
	while (start < block_tab_size(maintab) && already_set(maintab[start]))
		start++;
	if (start > block_tab_size(maintab) || !(maintab[start]).block)
		return (0);
	if (already_set(maintab[start]))
		return (0);
	if (!placenext((maintab[start]).block, grid, start + 'A', 0))
		return (combination(maintab, start + 1, grid));
	else
		maintab[start] = mark_as_set(maintab[start]);
	if (combination(maintab, 0, grid))
		return (1);
	else
	{
		maintab[start] = mark_as_notset(maintab[start]);
		eraseblock(grid, start + 'A');
		return (combination(maintab, start + 1, grid));
	}
	return (0);
}
