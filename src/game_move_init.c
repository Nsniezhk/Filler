/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 14:00:42 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/07/25 14:00:45 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

static	int		free_return(char **line, int ret)
{
	if (line != NULL)
		ft_strdel(line);
	return (ret);
}

static	void	heatmap_init(t_battle *hm, int hero, int enemy)
{
	int		row;
	int		elem;
	char	*line;

	row = 0;
	hm->heat_map = (int**)ft_memalloc(sizeof(int*) * hm->size->y);
	while (row < hm->size->y)
	{
		elem = 0;
		get_next_line(0, &line);
		hm->heat_map[row] = (int*)ft_memalloc(sizeof(int) * hm->size->x);
		while (elem < hm->size->x)
		{
			if (line[elem + 4] == '.')
				hm->heat_map[row][elem] = 0;
			else if (line[elem + 4] == hero)
				hm->heat_map[row][elem] = -1;
			else if (line[elem + 4] == enemy)
				hm->heat_map[row][elem] = -2;
			elem++;
		}
		row++;
		ft_strdel(&line);
	}
}

static	int		piece_init(t_token *p)
{
	int		row;
	char	*line;

	row = 0;
	if (!(p->piece = (char**)ft_memalloc(sizeof(char*) * p->size->y)))
		return (0);
	while (row < p->size->y)
	{
		get_next_line(0, &line);
		p->piece[row] = ft_strdup(&(*line));
		row++;
		ft_strdel(&line);
	}
	p->piece[row] = NULL;
	return (1);
}

static	int		battle_init(t_battle *field,
				t_token *fig, int hero, int enemy)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_strstr(line, "Plateau"))
	{
		field->size->y = ft_atoi(&line[7]);
		field->size->x = ft_atoi(&line[7 + ft_numlen(field->size->y) + 1]);
		ft_strdel(&line);
		get_next_line(0, &line);
		ft_strdel(&line);
		heatmap_init(&(*field), hero, enemy);
	}
	else
		return (free_return(&line, 0));
	get_next_line(0, &line);
	if (ft_strstr(line, "Piece"))
	{
		fig->size->y = ft_atoi(&line[5]);
		fig->size->x = ft_atoi(&line[5 + ft_numlen(fig->size->y)] + 1);
		if (!(piece_init(&(*fig))))
			return (free_return(&line, 0));
	}
	else
		return (free_return(&line, 0));
	return (free_return(&line, 1));
}

int				game_move_init(t_battle *field, t_token *p, int h, int e)
{
	if (!(field->size = ft_memalloc(sizeof(t_point))) ||
		!(field->pos = ft_memalloc(sizeof(t_point))) ||
		!(field->shift = ft_memalloc(sizeof(t_point))) ||
		!(field->save_pos = ft_memalloc(sizeof(t_point))) ||
		!(field->print = ft_memalloc(sizeof(t_point))) ||
		!(p->size = ft_memalloc(sizeof(t_point))) ||
		!(p->star = ft_memalloc(sizeof(t_point))) ||
		!(battle_init(&(*field), &(*p), h, e)))
		return (0);
	else
		return (1);
}
