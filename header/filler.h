/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 14:11:24 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/07/30 14:11:26 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

typedef	struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_token
{
	t_point		*size;
	t_point		*star;
	char		**piece;
}				t_token;

typedef	struct	s_battle
{
	int			**heat_map;
	int			battle;
	int			s;
	int			prev_s;
	t_point		*size;
	t_point		*pos;
	t_point		*shift;
	t_point		*save_pos;
	t_point		*print;
}				t_battle;

int				game_move_init(t_battle *field, t_token *p, int h, int e);
void			enemy_heatmap(t_battle *field);
void			for_each_position(t_battle *hm, t_token *p);

#endif
