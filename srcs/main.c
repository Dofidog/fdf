/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:16:06 by tpaaso            #+#    #+#             */
/*   Updated: 2020/10/08 18:07:57 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argv, char **argc)
{
	t_fdf *data;

	if (argv != 2)
	{
		ft_putendl("FdF invalid arguments");
		exit(-1);
	}
	data = (t_fdf*)malloc(sizeof(t_fdf));
	read_map(argc[1], data);
	data->mlx_ptr = mlx_init();
	data->horizontal = 0.8;
	data->vertical = 0.8;
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "FdF");
	draw_map(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
