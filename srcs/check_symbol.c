/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_symbol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <tsorabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:10:02 by tsorabel          #+#    #+#             */
/*   Updated: 2022/11/22 11:47:45 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/so_long.h"

void	check_symbol(char **map, t_global *glo)
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
			if (map[y][j] != '1' && map[y][j] != '0' &&
				map[y][j] != 'P' && map[y][j] != 'E' && map[y][j] != 'C')
				glo->rd_digit += 1;
			j++;
		}
	}
}
