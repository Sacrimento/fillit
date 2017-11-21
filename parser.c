/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:16:22 by abouvero          #+#    #+#             */
/*   Updated: 2017/11/19 18:09:14 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char          *remove_nl(char *b)
{
  int   i;
  int   j;
  char  *new_b;

  new_b = ft_strnew(ft_strlen(b));
  i = 0;
  j = 0;
  while (b[i])
  {
    if (b[i] == '\n')
      i++;
    new_b[j++] = b[i];
    i++;
  }
  return (new_b);
}

char          *tetri_parser_exce(char *b)
{
  char   *parsed;

  parsed = remove_nl(b);
  if (ft_strstr(parsed, "###..#"))
    parsed = "rdbd";
  else if (ft_strstr(parsed, "#...##..#"))
    parsed = "urbu";
  else if (ft_strstr(parsed, "#..##...#"))
    parsed = "ulbu";
  else if (ft_strstr(parsed, "#..###"))
    parsed = "rubr";
  else
    parsed = NULL;
  return (parsed);
}

int           get_left(char *b)
{
  int   i;
  int   diese;

  i = 0;
  diese = 4;
  while (b[i])
  {
    if (b[i] == '#' && diese % 5 > (i + 1) % 5)
      diese = i + 1;
    i++;
  }
  return (diese - 1);
}

char          *block_parser(char *b)
{
  int     i;
  int     j;
  char    *parsed;

  i = get_left(b);
  j = 0;
  if ((parsed = tetri_parser_exce(b)))
    return (parsed);
  parsed = ft_strnew(3);
  while (j < 3)
  {
    if (b[i + 1] == '#')
    {
      parsed[j++] = 'r';
	  j++;
      i++;
    }
    else if (b[i + 5] == '#')
    {
      parsed[j++] = 'd';
      i += 5;
    }
    else if (b[i - 5] == '#')
    {
      parsed[j++] = 'u';
      i -= 5;
	}
  }
  return (parsed);
}
