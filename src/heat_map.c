/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:42:19 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/08/17 13:42:22 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	int		return_max_abs(t_point *p1, t_point *p2)
{
	t_point res;

	res.x = (p2->x - p1->x >= 0) ? (p2->x - p1->x) : ((p2->x - p1->x) * -1);
	res.y = (p2->y - p1->y >= 0) ? (p2->y - p1->y) : ((p2->y - p1->y) * -1);
	return ((res.x >= res.y) ? res.x : res.y);
}

static	void	chebyshev_distance(t_battle *field, t_point *enemy)
{
	t_point size;
	int		res;

	size.y = -1;
	while (++size.y < field->size->y)
	{
		size.x = -1;
		while (++size.x < field->size->x)
		{
			if (field->heat_map[size.y][size.x] == 0)
				field->heat_map[size.y][size.x] =
			return_max_abs(&size, &(*enemy));
			else if (field->heat_map[size.y][size.x] > 0)
			{
				if ((res = return_max_abs(&size, &(*enemy))) <
					field->heat_map[size.y][size.x])
					field->heat_map[size.y][size.x] = res;
			}
		}
	}
}

void			enemy_heatmap(t_battle *field)
{
	t_point	enemy;

	enemy.y = -1;
	while (++enemy.y < field->size->y)
	{
		enemy.x = -1;
		while (++enemy.x < field->size->x)
		{
			if (field->heat_map[enemy.y][enemy.x] == -2)
				chebyshev_distance(&(*field), &enemy);
		}
	}
}
