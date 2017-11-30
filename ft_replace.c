/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:37:02 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/30 18:38:55 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_replace(list history, char *block, char **grid, char letter)
{
	if (block_exists(grid))
	{
		save_current_pos(history, grid, letter));
		ft_erase_block(grid, letter);
	}
	ft_placenext(block, letter);
	if (already_tried(grid, letter, history))
	{
		place_somewhere_esle(block, grid);
	}


	
}
