/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:45:43 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/06 14:45:45 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				is_blocks_left(t_block_sort *tab)
{
	int		i;

	i = 0;
	while ((tab[i]).block)
	{
		if (!((tab[i]).placed))
			return (1);
		i++;
	}
	return (0);
}

int				block_tab_size(t_block_sort *tab)
{
	int		i;

	i = 0;
	while ((tab[i]).block)
		i++;
	return (i - 1);
}

int				already_set(t_block_sort block)
{
	if (block.placed)
		return (1);
	return (0);
}

t_block_sort	mark_as_set(t_block_sort block)
{
	block.placed = 1;
	return (block);
}

t_block_sort	mark_as_notset(t_block_sort block)
{
	block.placed = 0;
	return (block);
}
