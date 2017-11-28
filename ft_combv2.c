/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combv2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:34:15 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/28 20:22:06 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int is_blocks_left(struct *s_block_sort);
static int already_set(struct s_block_sort);
static void mark_as_set(struct s_block_sort);
static void mark_as_notset(struct s_block_sort);

/* ft_combv2 a combinasion generator with recursive backtracking
 * ///////////////=================================================
 * maintab is a struct array with the blocks in alphabetic order
 * curentab was a fresh tab large as maintab where we stored the current combinasion
 * trough the recursion, quite useless : I try to do the job without
 * it but it use to help me visualise the current action
 * ///////////////=================================================
 */

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
