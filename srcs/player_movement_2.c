/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <tsorabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:46:34 by tsorabel          #+#    #+#             */
/*   Updated: 2022/11/22 11:47:48 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/so_long.h"

int	player_move_down_3(t_global *glo, int i)
{
	if (glo->map[glo->p_y + 1][glo->p_x] == '0' && i == 0)
	{
		if (glo->map[glo->p_y][glo->p_x] == 'P')
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_s_e.img, (32 * glo->p_x), (32 * (glo->p_y)));
		else
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_floor.img, (32 * glo->p_x), (32 * glo->p_y));
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_g_f.img, (32 * glo->p_x), (32 * (glo->p_y + 1)));
		glo->p_y += 1;
		init_bonnus(glo);
		return (1);
	}
	return (0);
}

int	player_move_right_3(t_global *glo, int i)
{
	if (glo->map[glo->p_y][glo->p_x + 1] == '0' && i == 0)
	{
		if (glo->map[glo->p_y][glo->p_x] == 'P')
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_s_e.img, (32 * glo->p_x), (32 * (glo->p_y)));
		else
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_floor.img, (32 * glo->p_x), (32 * glo->p_y));
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_g_r.img, (32 * (glo->p_x + 1)), (32 * glo->p_y));
		glo->p_x += 1;
		init_bonnus(glo);
		return (1);
	}
	return (0);
}

int	player_move_left_3(t_global *glo, int i)
{
	if (glo->map[glo->p_y][glo->p_x - 1] == '0' && i == 0)
	{
		if (glo->map[glo->p_y][glo->p_x] == 'P')
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_s_e.img, (32 * glo->p_x), (32 * (glo->p_y)));
		else
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_floor.img, (32 * glo->p_x), (32 * glo->p_y));
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_g_l.img, (32 * (glo->p_x - 1)), (32 * glo->p_y));
		glo->p_x -= 1;
		init_bonnus(glo);
		return (1);
	}
	return (0);
}

int	player_move_top_3(t_global *glo, int i)
{	
	if (glo->map[glo->p_y - 1][glo->p_x] == '0' && i == 0)
	{
		if (glo->map[glo->p_y][glo->p_x] == 'P')
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_s_e.img, (32 * glo->p_x), (32 * (glo->p_y)));
		else
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_floor.img, (32 * glo->p_x), (32 * glo->p_y));
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_g_b.img, (32 * glo->p_x), (32 * (glo->p_y - 1)));
		glo->p_y -= 1;
		init_bonnus(glo);
		return (1);
	}
	return (0);
}
