/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:59:29 by abouvero          #+#    #+#             */
/*   Updated: 2017/11/22 15:34:28 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strstr(const char *haystack, const char *needle)
{
	int			i;
	int			j;
	const char	*ptr;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			while (needle[j] && haystack[i + j] == needle[j])
			{
				j++;
				if (needle[j] == '\0')
				{
					return (1);
				}
			}
		}
		i++;
	}
	return (0);
}
