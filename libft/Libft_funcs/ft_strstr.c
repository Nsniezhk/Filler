/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:09:06 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/02/24 16:04:45 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(const char *str, const char *search)
{
	int i;
	int j;

	i = 0;
	if (search[i] == 0)
		return (NULL);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == search[j])
		{
			j++;
			if (search[j] == '\0')
				return ((char*)&str[i]);
		}
		i++;
	}
	return (NULL);
}
