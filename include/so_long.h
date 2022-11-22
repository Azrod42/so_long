/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <tsorabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:43:45 by tsorabel          #+#    #+#             */
/*   Updated: 2022/11/22 12:48:25 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER 16384
# define GAMENAME "so_long by tsorabel"
# define BONNUS 0

# include<sys/types.h>
# include<sys/stat.h>
# include<fcntl.h>
# include"../minilibx/mlx.h"
# include"../libft/libft.h"

typedef struct s_pos
{
	int			x;
	int			y;
	int			exit;
	int			action;
}				t_pos;

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_data		img_floor;
	t_data		img_wall;
	t_data		img_coin;
	t_data		img_exit;
	t_data		img_s_e;
	t_data		img_s_f;
	t_data		img_s_b;
	t_data		img_s_l;
	t_data		img_s_r;
	t_data		img_g_f;
	t_data		img_g_b;
	t_data		img_g_l;
	t_data		img_g_r;
	t_data		img_exit_open;
	t_data		img_exit_p;
	t_data		img_mov_b;
	t_data		img_me_b;
	t_data		img_nt_b;
	t_data		img_1;
	t_data		img_2;
	t_data		img_3;
	t_data		img_4;
	t_data		img_5;
	t_data		img_6;
	t_data		img_7;
	t_data		img_8;
	t_data		img_9;
	t_data		img_0;

}				t_mlx;

typedef struct s_global
{
	int		x_pannel;
	int		y_pannel;
	char	**map;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		nb_coin;
	int		algo_coin;
	int		coin_pick;
	int		move;
	char	end;
	char	e_d_o;
	int		rd_digit;
	int		b_px;
	t_mlx	mlx;
}			t_global;

char	**map_read_check(char *src, int *error, t_global *glo);
int		check_size(char **map, t_global *glo);
int		check_map_req(char **map);
int		check_border(char **map);
int		check_digit(char **map);
int		algo_is_way(char **map, t_global *glo);
void	window_manager(t_global *glo, char **map);
int		create_trgb(unsigned char t, unsigned char r,
			unsigned char g, unsigned char b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	init_texture(t_global *glo);
int		number_symbol(char **map, char digit);
void	spawn_pos(char **map, t_global *glo);
void	player_move_down(t_global *glo);
int		player_move_down_2(t_global *glo, int c, int t);
int		player_move_down_3(t_global *glo, int i);
void	player_move_right(t_global *glo);
int		player_move_right_2(t_global *glo, int c, int t);
int		player_move_right_3(t_global *glo, int i);
void	player_move_left(t_global *glo);
int		player_move_left_2(t_global *glo, int c, int t);
int		player_move_left_3(t_global *glo, int i);
void	player_move_top(t_global *glo);
int		player_move_top_2(t_global *glo, int c, int t);
int		player_move_top_3(t_global *glo, int i);
void	exit_open(t_global *glo);
int		walk(int keycode, t_global *glo);
void	check_symbol(char **map, t_global *glo);
void	init_bonnus(t_global *glo);
int		check_argv(char *argv);

#endif
