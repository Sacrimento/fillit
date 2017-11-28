/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combv2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:34:15 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/28 19:55:06 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int endoftab(struct	*);
static int already_set(struct s_block_sort);
static void mark_as_set(struct s_block_sort);

//maintab is a struct array with the blocks in alphabetic order
//curentab was a fresh tab large as maintab, quite useless : I try to do the job without it

int combv2(struct t_block_sort *maintab, int start)
{
	if (!endoftab(curentab[0]))
		return (1);
	while (!already_set(maintab[start]))
		start++;
//if we can't place this block, we are retring the current recursion with another start
	if (!ft_placenext(maintab[start]))
		combv2(maintab, curentab, start);
	else
		mark_as_set(maintab[start]);
	start = 0;
	if (combv2(maintab, start))
		
}
