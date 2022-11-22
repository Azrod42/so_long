/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <tsorabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:13:39 by tsorabel          #+#    #+#             */
/*   Updated: 2022/11/22 11:47:43 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/so_long.h"

int	number_symbol(char **map, char digit)
{
	int	j;
	int	y;
	int	res;

	y = 0;
	res = 0;
	j = 0;
	while (map[y])
		y++;
	while (--y > 0)
	{
		j = 0;
		while (map[y][j])
		{
			if (map[y][j] == digit)
				res++;
			j++;
		}
	}
	return (res);
}

int	check_digit(char **map)
{
	int	p;
	int	e;
	int	c;

	p = number_symbol(map, 'P');
	e = number_symbol(map, 'E');
	c = number_symbol(map, 'C');
	if (p > 1 || e > 1 || c < 1)
	{
		if (p > 1)
			ft_printf("Error\nToo manny player !\n");
		if (e > 1)
			ft_printf("Error\nToo manny exit !\n");
		if (c < 1)
			ft_printf("Error\nNot enough collectible !\n");
		return (1);
	}
	return (0);
}

int	check_size(char **map, t_global *glo)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	x = 0;
	i = 0;
	while (map[y])
		y++;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) > x)
			x = ft_strlen(map[i]);
		i++;
	}
	glo->x_pannel = x;
	glo->y_pannel = y;
	if (x < 5 || y < 3)
	{
		ft_printf("Error\nMap is to small.\n");
		return (1);
	}
	return (0);
}

int	check_map_req(char **map)
{
	int	i;
	int	p;
	int	len;

	i = 0;
	p = 0;
	while (map[p])
		p++;
	len = ft_strlen(map[0]);
	while ((int)ft_strlen(map[i]) == len && i < p - 1)
		i++;
	if ((int)ft_strlen(map[i]) != len || p > len)
	{
		ft_printf("Error\nMap is not rectangular !\n");
		return (2);
	}
	return (0);
}

int	check_border(char **map)
{
	int	i;
	int	j;
	int	p;
	int	bbdr;

	bbdr = 0;
	p = 0;
	while (map[p])
		p++;
	j = 0;
	while (map[0][j] == '1' && map[p - 1][j] == '1' &&
		map[0][j + 1] && map[p - 1][j])
		j++;
	if (map[0][j] != '1' || map[p - 1][j] != '1')
		bbdr++;
	j = 0;
	i = ft_strlen(map[0]) - 1;
	while (map[j][0] == '1' && map[j][i] == '1' && j < p - 1)
		j++;
	if (map[j][0] != '1' || map[j][i] != '1' || j < p - 1)
		bbdr++;
	if (bbdr)
		ft_printf("Error\nThe map is not surrounded by a wall.\n");
	return (bbdr);
}
