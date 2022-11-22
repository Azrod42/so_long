/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <tsorabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:55:12 by tsorabel          #+#    #+#             */
/*   Updated: 2022/11/22 11:47:46 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/so_long.h"

int	walk(int keycode, t_global *glo)
{
	if (keycode == 53)
		exit(0);
	if (!glo->end)
	{
		if (keycode == 1)
			player_move_down(glo);
		if (keycode == 2)
			player_move_right(glo);
		if (keycode == 0)
			player_move_left(glo);
		if (keycode == 13)
			player_move_top(glo);
	}
	else
		exit(0);
	exit_open(glo);
	return (keycode);
}

int	player_move_down_2(t_global *glo, int c, int t)
{
	if (glo->map[glo->p_y + 1][glo->p_x] == 'E' && t == c)
	{
		if (glo->map[glo->p_y][glo->p_x] == 'P')
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_s_e.img, (32 * glo->p_x), (32 * (glo->p_y)));
		else
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_floor.img, (32 * glo->p_x), (32 * glo->p_y));
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_exit_p.img, (32 * glo->p_x), (32 * (glo->p_y + 1)));
		glo->end = 1;
		glo->p_y += 1;
		return (1);
	}
	else if (glo->map[glo->p_y + 1][glo->p_x] == 'P')
	{
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_floor.img, (32 * glo->p_x), (32 * glo->p_y));
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_s_f.img, (32 * glo->p_x), (32 * (glo->p_y + 1)));
		glo->p_y += 1;
		init_bonnus(glo);
		return (1);
	}
	return (0);
}

int	player_move_right_2(t_global *glo, int c, int t)
{
	if (glo->map[glo->p_y][glo->p_x + 1] == 'E' && t == c)
	{
		if (glo->map[glo->p_y][glo->p_x] == 'P')
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_s_e.img, (32 * glo->p_x), (32 * (glo->p_y)));
		else
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_floor.img, (32 * glo->p_x), (32 * glo->p_y));
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_exit_p.img, (32 * (glo->p_x + 1)), (32 * glo->p_y));
		glo->end = 1;
		glo->p_x += 1;
		return (1);
	}
	else if (glo->map[glo->p_y][glo->p_x + 1] == 'P')
	{
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_floor.img, (32 * glo->p_x), (32 * glo->p_y));
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_s_r.img, 32 * (glo->p_x + 1), (32 * glo->p_y));
		glo->p_x += 1;
		init_bonnus(glo);
		return (1);
	}
	return (0);
}

int	player_move_left_2(t_global *glo, int c, int t)
{
	if (glo->map[glo->p_y][glo->p_x - 1] == 'E' && t == c)
	{
		if (glo->map[glo->p_y][glo->p_x] == 'P')
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_s_e.img, (32 * glo->p_x), (32 * (glo->p_y)));
		else
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_floor.img, (32 * glo->p_x), (32 * glo->p_y));
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_exit_p.img, (32 * (glo->p_x - 1)), (32 * glo->p_y));
		glo->end = 1;
		glo->p_x -= 1;
		return (1);
	}
	else if (glo->map[glo->p_y][glo->p_x - 1] == 'P')
	{
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_floor.img, (32 * glo->p_x), (32 * glo->p_y));
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_s_l.img, (32 * (glo->p_x - 1)), (32 * (glo->p_y)));
		init_bonnus(glo);
		glo->p_x -= 1;
		return (1);
	}
	return (0);
}

int	player_move_top_2(t_global *glo, int c, int t)
{	
	if (glo->map[glo->p_y - 1][glo->p_x] == 'E' && t == c)
	{
		if (glo->map[glo->p_y - 1][glo->p_x] == 'P')
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_s_e.img, (32 * glo->p_x), (32 * (glo->p_y)));
		else
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_floor.img, (32 * glo->p_x), (32 * glo->p_y));
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_exit_p.img, (32 * glo->p_x), (32 * (glo->p_y - 1)));
		glo->end = 1;
		glo->p_y -= 1;
		return (1);
	}
	else if (glo->map[glo->p_y - 1][glo->p_x] == 'P')
	{
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_floor.img, (32 * glo->p_x), (32 * glo->p_y));
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_s_b.img, (32 * (glo->p_x)), (32 * (glo->p_y - 1)));
		init_bonnus(glo);
		glo->p_y -= 1;
		return (1);
	}
	return (0);
}
