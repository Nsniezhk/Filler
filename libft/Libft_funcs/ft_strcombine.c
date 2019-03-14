/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcombine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:31:38 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/08/04 16:32:04 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcombine(char *a, char *b)
{
	char	*ret;

	ret = ft_strjoin(a, b);
	ft_strdel(&a);
	ft_strdel(&b);
	return (ret);
}
