/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <tsorabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:23:01 by tsorabel          #+#    #+#             */
/*   Updated: 2022/11/22 12:42:29 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/so_long.h"

void	exit_open(t_global *glo)
{
	if (!glo->e_d_o && glo->algo_coin == glo->coin_pick)
	{
		glo->e_d_o = 1;
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_exit_open.img, (32 * glo->e_x), (32 * glo->e_y));
	}
}

void	put_image(t_global *glo, int x, int y, char **map)
{
	if (map[y][x] == '1')
		mlx_put_image_to_window(glo->mlx.mlx,
			glo->mlx.mlx_win, glo->mlx.img_wall.img, (32 * x), (32 * y));
	if (map[y][x] == '0')
		mlx_put_image_to_window(glo->mlx.mlx,
			glo->mlx.mlx_win, glo->mlx.img_floor.img, (32 * x), (32 * y));
	if (map[y][x] == 'P')
		mlx_put_image_to_window(glo->mlx.mlx,
			glo->mlx.mlx_win, glo->mlx.img_s_f.img, (32 * x), (32 * y));
	if (map[y][x] == 'E')
		mlx_put_image_to_window(glo->mlx.mlx,
			glo->mlx.mlx_win, glo->mlx.img_exit.img, (32 * x), (32 * y));
	if (map[y][x] == 'C')
		mlx_put_image_to_window(glo->mlx.mlx,
			glo->mlx.mlx_win, glo->mlx.img_coin.img, (32 * x), (32 * y));
}

void	init_map(t_global *glo, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < glo->y_pannel)
	{
		x = 0;
		while (x < glo->x_pannel)
		{
			put_image(glo, x, y, map);
			x++;
		}
		y++;
	}
}

int	leave(int key, t_global *glo)
{
	(void)key;
	(void)glo;
	exit(0);
}

void	window_manager(t_global *glo, char **map)
{	
	glo->mlx.mlx = mlx_init();
	glo->mlx.mlx_win = mlx_new_window(glo->mlx.mlx,
			glo->x_pannel * 32, glo->y_pannel * 32, GAMENAME);
	init_texture(glo);
	init_map(glo, map);
	init_bonnus(glo);
	mlx_hook(glo->mlx.mlx_win, 2, (1L << 0), walk, glo);
	mlx_hook(glo->mlx.mlx_win, 17, (1L << 17), leave, glo);
	mlx_loop(glo->mlx.mlx);
}
