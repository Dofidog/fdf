/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 13:02:52 by tpaaso            #+#    #+#             */
/*   Updated: 2020/11/28 12:15:12 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_fdf *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(-1);
	}
	if (key == 13 || key == 0 || key == 1 || key == 2)
		rotate(key, data);
	if (key == 69)
		data->zoom += 5;
	if (key == 78)
		data->zoom -= 5;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_map(data);
	return (0);
}

int		rotate(int key, t_fdf *data)
{
	if (key == 13)
		data->vertical += 0.1;
	if (key == 0)
		data->horizontal += 0.1;
	if (key == 1)
		data->vertical -= 0.1;
	if (key == 2)
		data->horizontal -= 0.1;
	return (0);
}
