/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <tsorabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:32:52 by tsorabel          #+#    #+#             */
/*   Updated: 2022/11/22 12:41:35 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/so_long.h"

int	main(int argc, char **argv)
{
	t_global	glo;
	int			error;

	glo.algo_coin = 0;
	glo.nb_coin = 0;
	if (argc == 1)
	{
		ft_printf("Error\nNo map added.\n");
		return (0);
	}
	error = check_argv(argv[1]);
	if (error == 0)
		glo.map = map_read_check(argv[1], &error, &glo);
	if (error > 0)
		return (0);
	window_manager(&glo, glo.map);
	return (0);
}
