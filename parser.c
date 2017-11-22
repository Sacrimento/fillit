/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:16:22 by abouvero          #+#    #+#             */
/*   Updated: 2017/11/22 11:19:37 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <string.h>

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
  else if (ft_strstr(parsed, "##..##"))
    parsed = "urdl";
  else
    parsed = NULL;
  return (parsed);
}

int           extreminos(char *b)
{
  int                         i;
  int                         expectopatrominos;
  int                         last_d;

  i = 0;
  expectopatrominos = 0;
  while (b[i])
  {
    while (b[i] && b[i] != '#')
      i++;
    if (b[i + 1] == '#')
      expectopatrominos++;
    if (b[i - 1] == '#')
      expectopatrominos++;
    if (b[i + 5] == '#')
      expectopatrominos++;
    if (b[i - 5] == '#')
      expectopatrominos++;
    if (expectopatrominos == 1)
      return (i);
    else
    {
      last_d = i;
      i++;
      expectopatrominos = 0;
    }
  }
  return (last_d);
}

char          *block_parser(char *b)
{
  int     i;
  int     j;
  char    *parsed;
  int     code;

  i = extreminos(b);
  j = 0;
  if ((parsed = tetri_parser_exce(b)))
    return (parsed);
  parsed = ft_strnew(3);
  while (j < 3)
  {
    if (b[i + 1] == '#' && code != -1)
    {
      code = 1;
      parsed[j++] = 'r';
      i++;
    }
    else if (b[i + 5] == '#' && code != -5)
    {
      code = 5;
      parsed[j++] = 'd';
      i += 5;
    }
    else if (b[i - 5] == '#' && code != 5)
    {
      code = -5;
      parsed[j++] = 'u';
      i -= 5;
	  }
    else if (b[i - 1] == '#' && code != 1)
    {
      code = -1;
      parsed[j++] = 'l';
      i--;
    }
    else
      error();
  }
  return (parsed);
}
