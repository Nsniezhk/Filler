/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 13:11:16 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/09/08 13:11:18 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

static	int			get_game_info(int *hero, int *enemy)
{
	char *line;

	get_next_line(0, &line);
	if (ft_strstr(line, "$$$"))
	{
		if (ft_strstr(line, "p1"))
		{
			ft_strdel(&line);
			*hero = 'O';
			*enemy = 'X';
			return (1);
		}
		else if (ft_strstr(line, "p2"))
		{
			ft_strdel(&line);
			*hero = 'X';
			*enemy = 'O';
			return (1);
		}
	}
	ft_strdel(&line);
	return (0);
}

static int			clear(t_battle *m, t_token *t)
{
	int i;

	i = 0;
	while (i < m->size->y)
		free(m->heat_map[i++]);
	free(m->heat_map);
	i = 0;
	while (i < t->size->y)
		free(t->piece[i++]);
	free(t->piece);
	free(t->size);
	free(t->star);
	free(t);
	free(m->size);
	free(m->pos);
	free(m->shift);
	free(m->save_pos);
	free(m->print);
	free(m);
	return (0);
}

int					main(void)
{
	t_token		*fig;
	t_battle	*field;
	int			hero;
	int			enemy;

	if ((get_game_info(&hero, &enemy)))
		while (1)
		{
			fig = ft_memalloc(sizeof(t_token));
			field = ft_memalloc(sizeof(t_battle));
			if (!(game_move_init(&(*field), &(*fig), hero, enemy)))
				return (clear(&(*field), &(*fig)));
			enemy_heatmap(&(*field));
			field->pos->y = -1;
			while (++field->pos->y < field->size->y)
			{
				field->pos->x = -1;
				while (++field->pos->x < field->size->x)
					if (field->heat_map[field->pos->y][field->pos->x] == -1)
						for_each_position(&(*field), &(*fig));
			}
			ft_printf("%d %d\n", field->print->y, field->print->x);
			clear(&(*field), &(*fig));
		}
	return (0);
}
