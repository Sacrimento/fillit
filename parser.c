/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:16:22 by abouvero          #+#    #+#             */
/*   Updated: 2017/11/16 11:17:41 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* 3222
** 1. Nb de points avant le premier diese
**      sur la ligne du block_
** 2. Nb de points entre les deux # suivants.
*/

static char   fpoint(char *b)
{
  int   i;
  char  c;

  i = 0;
  c = 0;
  while (b[i])
  {
    if (b[i] == '\n')
      c = 0;
    else if (b[i] == '.')
      c++;
    else if (b[i] == '#')
      return (c);
    i++;
  }
  return (0);
}

char          *block_parser(char *b)
{
  int     j;
  int     i;
  int     point;
  char    *parsed;

  i = 0;
  j = 1;

  parsed = ft_strnew(4);
  parsed[0] = fpoint(b) + '0';
  parsed[4] = '\0';
  while (j < 4)
  {
    point = 0;
    while (b[i] != '#')
    {
      if (b[i] == '.')
        point++;
      i++;
    }
    printf("%d\n", point);
    parsed[j] = point + '0';
    j++;
  }
  printf("%s\n", parsed);
  return (parsed);
}
