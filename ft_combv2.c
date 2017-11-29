/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combv2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:34:15 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/29 11:13:40 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* ft_combv2 a combinasion generator with recursive backtracking
 * ///////////////=================================================
 * maintab is a struct array with the blocks in alphabetic order
 * curentab was a fresh tab large as maintab where we stored the current combinasion
 * trough the recursion, quite useless : I try to do the job without
 * it but it use to help me visualise the current action
 * ///////////////=================================================
 */

static int			is_blocks_left(t_block_sort *tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (!((tab[i]).placed))
			return (0);
		i++;
	}
	return (1);
}

static int			already_set(t_block_sort block)
{
	if (block.placed)
		return (1);
	return (0);
}

static t_block_sort	mark_as_set(t_block_sort block)
{
	block.placed = 1;
	return (block);
}

static t_block_sort	mark_as_nset(t_block_sort block)
{
	block.placed = 0;
	return (block);
}

int combv2(struct s_block_sort *maintab, int start)
{
	if (end_of_tab(maintab[start]))
		return (0);
	if (!is_blocks_left(maintab))
		return (1);
	while (!already_set(maintab[start]))
		start++;
//if we can't place this block, we are retring the current recursion with another start
	if (!ft_placenext(maintab[start]))
		combv2(maintab, start + 1);
	else
		mark_as_set(maintab[start]);
	if (combv2(maintab, 0))
		return (1);
	else
	{
		mark_as_notset(maintab[start]);
		combv2(maintab, start + 1);
	}
	return (0);
}
