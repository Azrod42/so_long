/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <tsorabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:16:30 by tsorabel          #+#    #+#             */
/*   Updated: 2022/11/22 11:48:10 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/so_long.h"

void	algo_check_coin(char **map, t_pos *pos, t_global *glo)
{
	if (map[pos->y - 1][pos->x] == 'C')
		glo->algo_coin += 1;
	if (map[pos->y + 1][pos->x] == 'C')
		glo->algo_coin += 1;
	if (map[pos->y][pos->x - 1] == 'C')
		glo->algo_coin += 1;
	if (map[pos->y][pos->x + 1] == 'C')
		glo->algo_coin += 1;
}

void	algo_set_way(char **map, t_pos *pos, t_global *glo)
{
	algo_check_coin(map, pos, glo);
	if (map[pos->y][pos->x] == 'P')
		map[pos->y][pos->x] = 'W';
	if (map[pos->y - 1][pos->x] == '0' || map[pos->y - 1][pos->x] == 'C')
	{
		pos->action += 1;
		map[pos->y - 1][pos->x] = 'W';
	}
	if (map[pos->y + 1][pos->x] == '0' || map[pos->y + 1][pos->x] == 'C')
	{
		pos->action += 1;
		map[pos->y + 1][pos->x] = 'W';
	}
	if (map[pos->y][pos->x - 1] == '0' || map[pos->y][pos->x - 1] == 'C')
	{
		pos->action += 1;
		map[pos->y][pos->x - 1] = 'W';
	}
	if (map[pos->y][pos->x + 1] == '0' || map[pos->y][pos->x + 1] == 'C')
	{
		pos->action += 1;
		map[pos->y][pos->x + 1] = 'W';
	}
}

void	algo_check_exit(char **map, t_pos *pos, t_global *glo)
{
	if (map[pos->y - 1][pos->x] == 'E')
	{
		glo->e_x = pos->x;
		glo->e_y = pos->y - 1;
		pos->exit += 1;
	}
	if (map[pos->y + 1][pos->x] == 'E')
	{
		glo->e_x = pos->x;
		glo->e_y = pos->y + 1;
		pos->exit += 1;
	}
	if (map[pos->y][pos->x - 1] == 'E')
	{
		glo->e_x = pos->x - 1;
		glo->e_y = pos->y;
		pos->exit += 1;
	}
	if (map[pos->y][pos->x + 1] == 'E')
	{
		glo->e_x = pos->x + 1;
		glo->e_y = pos->y;
		pos->exit += 1;
	}
}

int	algo_check_is_exit(char **map, t_global *glo)
{
	t_pos	pos;

	pos.y = 0;
	pos.x = 0;
	pos.exit = 0;
	while (map[pos.y])
		pos.y++;
	while (--pos.y > 0)
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] == 'W')
				algo_check_exit(map, &pos, glo);
			pos.x++;
		}
	}
	if (pos.exit > 0)
		return (1);
	return (0);
}

int	algo_is_way(char **map, t_global *glo)
{
	t_pos	pos;

	pos.y = 0;
	pos.x = 0;
	pos.action = 1;
	while (pos.action)
	{
		pos.action = 0;
		while (map[pos.y])
			pos.y += 1;
		while (--pos.y > 0)
		{
			pos.x = 0;
			while (map[pos.y][pos.x])
			{
				if (map[pos.y][pos.x] == 'P' || map[pos.y][pos.x] == 'W')
					algo_set_way(map, &pos, glo);
				pos.x++;
			}
		}
	}
	if (algo_check_is_exit(map, glo))
		return (0);
	ft_printf("Error\nNo possible way\n");
	return (1);
}
