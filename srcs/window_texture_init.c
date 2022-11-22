/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_texture_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <tsorabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:21:03 by tsorabel          #+#    #+#             */
/*   Updated: 2022/11/22 11:47:51 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/so_long.h"

void	init_player_on_ground(t_global *glo)
{
	int	img_width;
	int	img_height;

	glo->mlx.img_g_f.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/g_f.xpm", &img_width, &img_height);
	glo->mlx.img_g_b.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/g_b.xpm", &img_width, &img_height);
	glo->mlx.img_g_r.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/g_r.xpm", &img_width, &img_height);
	glo->mlx.img_g_l.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/g_l.xpm", &img_width, &img_height);
}

void	init_player_on_spawn(t_global *glo)
{
	int	img_width;
	int	img_height;

	glo->mlx.img_s_f.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/s_f.xpm", &img_width, &img_height);
	glo->mlx.img_s_b.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/s_b.xpm", &img_width, &img_height);
	glo->mlx.img_s_r.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/s_r.xpm", &img_width, &img_height);
	glo->mlx.img_s_l.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/s_l.xpm", &img_width, &img_height);
}

void	init_number_img(t_global *glo)
{
	int	img_width;
	int	img_height;

	glo->mlx.img_1.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/1.xpm", &img_width, &img_height);
	glo->mlx.img_2.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/2.xpm", &img_width, &img_height);
	glo->mlx.img_3.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/3.xpm", &img_width, &img_height);
	glo->mlx.img_4.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/4.xpm", &img_width, &img_height);
	glo->mlx.img_5.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/5.xpm", &img_width, &img_height);
	glo->mlx.img_6.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/6.xpm", &img_width, &img_height);
	glo->mlx.img_7.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/7.xpm", &img_width, &img_height);
	glo->mlx.img_8.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/8.xpm", &img_width, &img_height);
	glo->mlx.img_9.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/9.xpm", &img_width, &img_height);
	glo->mlx.img_0.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/0.xpm", &img_width, &img_height);
}

void	texture_bonnus(t_global *glo)
{
	int	img_width;
	int	img_height;

	glo->mlx.img_mov_b.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/mov.xpm", &img_width, &img_height);
	glo->mlx.img_me_b.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/eme.xpm", &img_width, &img_height);
	glo->mlx.img_nt_b.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/nt.xpm", &img_width, &img_height);
}

void	init_texture(t_global *glo)
{
	int		img_width;
	int		img_height;

	glo->mlx.img_floor.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/floor_1.xpm", &img_width, &img_height);
	glo->mlx.img_wall.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/wall_1.xpm", &img_width, &img_height);
	glo->mlx.img_coin.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/coin.xpm", &img_width, &img_height);
	glo->mlx.img_s_e.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/spawn_empty.xpm", &img_width, &img_height);
	glo->mlx.img_exit.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/exit.xpm", &img_width, &img_height);
	glo->mlx.img_exit_open.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/exit_open.xpm", &img_width, &img_height);
	glo->mlx.img_exit_p.img = mlx_xpm_file_to_image(glo->mlx.mlx,
			"./img/exit_p.xpm", &img_width, &img_height);
	init_player_on_spawn(glo);
	init_player_on_ground(glo);
	init_number_img(glo);
	texture_bonnus(glo);
}
