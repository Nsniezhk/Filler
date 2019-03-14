/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 13:40:03 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/08/29 13:40:05 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	int		count_field(t_battle *hm, int shift_y, int shift_x)
{
	int	y;
	int	x;

	y = hm->pos->y + shift_y - hm->save_pos->y;
	x = hm->pos->x + shift_x - hm->save_pos->x;
	if (y < 0 || y >= hm->size->y || x < 0 || x >= hm->size->x)
		return (0);
	if (hm->heat_map[y][x] == -1 || hm->heat_map[y][x] == -2)
		if (shift_x != hm->save_pos->x || shift_y != hm->save_pos->y)
			return (0);
	if (hm->heat_map[y][x] != -1)
		hm->s += hm->heat_map[y][x];
	return (1);
}

static	int		count_place(t_battle *hm, t_token *p, int y, int x)
{
	hm->save_pos->y = y + 1;
	hm->save_pos->x = x + 1;
	while (++y < p->size->y)
	{
		while (++x < p->size->x)
			if (p->piece[y][x] == '*')
				if (!(count_field(&(*hm), y, x)))
					return (0);
		x = -1;
	}
	y = hm->save_pos->y + 1;
	x = hm->save_pos->x + 1;
	while (--y >= 0)
	{
		while (--x >= 0)
			if (p->piece[y][x] == '*')
				if (!(count_field(&(*hm), y, x)))
					return (0);
		x = p->size->x;
	}
	return (1);
}

static	int		pos_move(t_token *p, int *y, int *x)
{
	if (*y == p->star->y && *x == p->star->x)
	{
		if (*x + 1 < p->size->x)
			(*x)++;
		else if (*y + 1 < p->size->y)
		{
			(*y)++;
			(*x) = 0;
		}
		else
			return (0);
	}
	return (1);
}

static	int		next_star(t_token *p, int *y, int *x)
{
	if (!(pos_move(&(*p), &(*y), &(*x))))
		return (0);
	while (*y < p->size->y)
	{
		while (*x < p->size->x)
		{
			if (p->piece[*y][*x] == '*')
			{
				p->star->y = *y;
				p->star->x = *x;
				return (1);
			}
			(*x)++;
		}
		(*x) = 0;
		(*y)++;
	}
	return (0);
}

void			for_each_position(t_battle *hm, t_token *p)
{
	hm->shift->y = 0;
	hm->shift->x = 0;
	p->star->y = -1;
	p->star->x = -1;
	while (next_star(&(*p), &hm->shift->y, &(hm)->shift->x))
	{
		hm->s = 0;
		if (count_place(&(*hm), &(*p), hm->shift->y - 1, hm->shift->x - 1))
		{
			if ((hm->s <= hm->prev_s && hm->s > 0) ||
				(hm->s > 0 && hm->prev_s == 0))
			{
				hm->prev_s = hm->s;
				hm->print->y = hm->pos->y - hm->shift->y;
				hm->print->x = hm->pos->x - hm->shift->x;
			}
		}
	}
}
