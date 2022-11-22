/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonnus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <tsorabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:22:44 by tsorabel          #+#    #+#             */
/*   Updated: 2022/11/22 13:01:55 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/so_long.h"

void	print_nu(t_global *glo, char nu, int px)
{
	if (nu == '1')
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_1.img, ((30 * 2) + 5 + px), ((32 * 0)));
	if (nu == '2')
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_2.img, ((30 * 2) + 5 + px), ((32 * 0)));
	if (nu == '3')
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_3.img, ((30 * 2) + 5 + px), ((32 * 0)));
	if (nu == '4')
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_4.img, ((30 * 2) + 5 + px), ((32 * 0)));
	if (nu == '5')
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_5.img, ((30 * 2) + 5 + px), ((32 * 0)));
}

void	print_nu_2(t_global *glo, char nu, int px)
{
	if (nu == '6')
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_6.img, ((30 * 2) + 5 + px), ((32 * 0)));
	if (nu == '7')
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_7.img, ((30 * 2) + 5 + px), ((32 * 0)));
	if (nu == '8')
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_8.img, ((30 * 2) + 5 + px), ((32 * 0)));
	if (nu == '9')
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_9.img, ((30 * 2) + 5 + px), ((32 * 0)));
	if (nu == '0')
		mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
			glo->mlx.img_0.img, ((30 * 2) + 5 + px), ((32 * 0)));
}

void	print_background(t_global *glo)
{
	mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
		glo->mlx.img_mov_b.img, (32 * 0), (32 * 0));
	mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
		glo->mlx.img_me_b.img, (32 * 1), (32 * 0));
	mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
		glo->mlx.img_nt_b.img, (32 * 2), (32 * 0));
	mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
		glo->mlx.img_wall.img, (32 * 3), (32 * 0));
	mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
		glo->mlx.img_wall.img, (32 * 4), (32 * 0));
	mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
		glo->mlx.img_wall.img, (32 * 5), (32 * 0));
	mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
		glo->mlx.img_wall.img, (32 * 6), (32 * 0));
	mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
		glo->mlx.img_wall.img, (32 * 7), (32 * 0));
	mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
		glo->mlx.img_wall.img, (32 * 8), (32 * 0));
	mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
		glo->mlx.img_wall.img, (32 * 9), (32 * 0));
	mlx_put_image_to_window(glo->mlx.mlx, glo->mlx.mlx_win,
		glo->mlx.img_wall.img, (32 * 10), (32 * 0));
}

void	init_bonnus(t_global *glo)
{
	int		i;
	char	*move;

	ft_printf("Movement counter : %d\n", glo->move);
	if (glo->move <= 2000000000)
		glo->move += 1;
	if (BONNUS == 1)
	{
		move = ft_itoa(glo->move);
		glo->b_px = 0;
		i = -1;
		print_background(glo);
		while (move[++i])
		{
			print_nu(glo, move[i], glo->b_px);
			print_nu_2(glo, move[i], glo->b_px);
			glo->b_px += 10;
		}
	}
}
