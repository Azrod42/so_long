/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_read_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <tsorabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:10:48 by tsorabel          #+#    #+#             */
/*   Updated: 2022/11/22 12:49:34 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/so_long.h"

void	check_coin(int algo, int coin, int *error, t_global *glo)
{
	if (!*error)
	{
		if (algo != coin)
		{
			*error += 1;
			ft_printf("Error\nNot all items are recoverable\n");
		}
		check_symbol(glo->map, glo);
		if (glo->rd_digit)
		{
			*error += 1;
			ft_printf("Error\nRandom digit on map\n");
		}
	}
}

int	check_argv(char *argv)
{
	if (argv[ft_strlen(argv) - 1] == 'r')
		if (argv[ft_strlen(argv) - 2] == 'e')
			if (argv[ft_strlen(argv) - 3] == 'b')
				if (argv[ft_strlen(argv) - 4] == '.')
					return (0);
	ft_printf("Error\nWrong file type\n");
	return (1);
}

char	*map_read(char *src, int *error)
{
	int		fd;
	int		read_len;
	char	*buffer;

	buffer = malloc(BUFFER + 1 * sizeof(char));
	fd = open(src, O_RDONLY);
	read_len = read(fd, buffer, BUFFER);
	if (read_len == -1 || read_len == BUFFER)
	{
		*error += 1;
		ft_printf("Error\nWhen reading the file\n");
		return (NULL);
	}
	buffer[read_len] = '\0';
	close(fd);
	return (buffer);
}

char	**map_read_check(char *src, int *error, t_global *glo)
{
	char	*map_read_fd;
	char	**map_algo;

	glo->rd_digit = 0;
	map_read_fd = map_read(src, error);
	if (!*error)
	{
		glo->map = ft_split(map_read_fd, '\n');
		map_algo = ft_split(map_read_fd, '\n');
		*error += check_size(glo->map, glo);
	}
	if (!*error)
		*error += check_digit(glo->map);
	if (!*error)
		*error += check_map_req(glo->map);
	if (!*error)
		*error += check_border(glo->map);
	if (!*error)
		*error += algo_is_way(map_algo, glo);
	if (!*error)
		glo->nb_coin = number_symbol(glo->map, 'C');
	if (!*error)
		spawn_pos(glo->map, glo);
	check_coin(glo->algo_coin, glo->nb_coin, error, glo);
	return (glo->map);
}
