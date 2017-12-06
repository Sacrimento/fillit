/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:44:59 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/06 14:45:01 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_grid(char **tab)
{
	int cursor;

	cursor = 0;
	while (tab[cursor] != 0)
	{
		ft_putstr(tab[cursor]);
		ft_putchar('\n');
		cursor++;
	}
}
