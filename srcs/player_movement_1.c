/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <tsorabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:34:27 by tsorabel          #+#    #+#             */
/*   Updated: 2022/11/22 11:47:47 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/so_long.h"

void	spawn_pos(char **map, t_global *glo)
{
	int	j;
	int	y;

	y = 0;
	j = 0;
	while (map[y])
		y++;
	while (--y > 0)
	{
		j = 0;
		while (map[y][j])
		{
			if (map[y][j] == 'P')
			{
				glo->p_x = j;
				glo->p_y = y;
				return ;
			}
			j++;
		}
	}
}

void	player_move_down(t_global *glo)
{
	int	i;

	i = player_move_down_2(glo, glo->coin_pick, glo->nb_coin);
	i = player_move_down_3(glo, i);
	if (glo->map[glo->p_y + 1][glo->p_x] == 'C' && i == 0)
	{
		if (glo->map[glo->p_y][glo->p_x] == 'P')
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_s_e.img, (32 * glo->p_x), (32 * (glo->p_y)));
		else
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_floor.img, (32 * glo->p_x), (32 * glo->p_y));
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_g_f.img, (32 * glo->p_x), (32 * (glo->p_y + 1)));
		glo->map[glo->p_y + 1][glo->p_x] = '0';
		glo->p_y += 1;
		glo->coin_pick += 1;
		init_bonnus(glo);
	}
}

void	player_move_right(t_global *glo)
{
	int	i;

	i = player_move_right_2(glo, glo->coin_pick, glo->nb_coin);
	i = player_move_right_3(glo, i);
	if (glo->map[glo->p_y][glo->p_x + 1] == 'C' && i == 0)
	{
		if (glo->map[glo->p_y][glo->p_x] == 'P')
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_s_e.img, (32 * glo->p_x), (32 * (glo->p_y)));
		else
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_floor.img, (32 * glo->p_x), (32 * glo->p_y));
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_g_r.img, (32 * (glo->p_x + 1)), (32 * glo->p_y));
		glo->map[glo->p_y][glo->p_x + 1] = '0';
		glo->p_x += 1;
		glo->coin_pick += 1;
		init_bonnus(glo);
	}
}

void	player_move_left(t_global *glo)
{
	int	i;

	i = player_move_left_2(glo, glo->coin_pick, glo->nb_coin);
	i = player_move_left_3(glo, i);
	if (glo->map[glo->p_y][glo->p_x - 1] == 'C' && i == 0)
	{
		if (glo->map[glo->p_y][glo->p_x] == 'P')
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_s_e.img, (32 * glo->p_x), (32 * (glo->p_y)));
		else
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_floor.img, (32 * glo->p_x), (32 * glo->p_y));
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_g_l.img, (32 * (glo->p_x - 1)), (32 * glo->p_y));
		glo->map[glo->p_y][glo->p_x - 1] = '0';
		glo->p_x -= 1;
		ft_printf("Movement counter : %d\n", glo->move += 1);
		init_bonnus(glo);
		glo->coin_pick += 1;
	}
}

void	player_move_top(t_global *glo)
{	
	int	i;

	i = player_move_top_2(glo, glo->coin_pick, glo->nb_coin);
	i = player_move_top_3(glo, i);
	if (glo->map[glo->p_y - 1][glo->p_x] == 'C' && i == 0)
	{
		if (glo->map[glo->p_y - 1][glo->p_x] == 'P')
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_s_e.img, (32 * glo->p_x), (32 * (glo->p_y)));
		else
			mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
				glo->mlx.img_floor.img, (32 * glo->p_x), (32 * glo->p_y));
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_g_b.img, (32 * glo->p_x), (32 * (glo->p_y - 1)));
		glo->map[glo->p_y - 1][glo->p_x] = '0';
		glo->p_y -= 1;
		init_bonnus(glo);
		glo->coin_pick += 1;
	}
}
