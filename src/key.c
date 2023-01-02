/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:02:03 by tpaaso            #+#    #+#             */
/*   Updated: 2022/04/21 14:49:06 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	key_move(int key, t_fdf *data)
{
	if (key == 126)
		data->hori -= 20;
	if (key == 125)
		data->hori += 20;
	if (key == 124)
		data->vert += 20;
	if (key == 123)
		data->vert -= 20;
}

void	key_isometric(int key, t_fdf *data)
{
	if (key == 91)
		data->isoy -= 0.1;
	if (key == 84)
		data->isoy += 0.1;
	if (key == 88)
		data->isox += 0.1;
	if (key == 86)
		data->isox -= 0.1;
}

void	key_color(int key, t_fdf *data)
{
	if (key == 5)
		data->color = 0x00ff00;
	if (key == 15)
		data->color = 0xff0000;
	if (key == 11)
		data->color = 0x0000ff;
}

int	deal_key(int key, t_fdf *data)
{
	if (key == 78)
		data->zoom -= 5;
	if (key == 69)
		data->zoom += 5;
	if (key == 53)
		exit(-1);
	if (key == 126 || key == 125 || key == 124 || key == 123)
		key_move(key, data);
	if (key == 5 || key == 15 || key == 11)
		key_color(key, data);
	if (key == 91 || key == 84 || key == 88 || key == 86)
		key_isometric(key, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_draw_map(data);
	return (0);
}
