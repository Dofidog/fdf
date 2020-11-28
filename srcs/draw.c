/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 13:10:24 by tpaaso            #+#    #+#             */
/*   Updated: 2020/11/28 12:08:41 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->horizontal);
	*y = (*x + *y) * sin(data->vertical) - z;
}

void	bresenham(float x, float y, t_fdf *data)
{
	data->z = data->xyz[(int)y][(int)x];
	data->z1 = data->xyz[(int)data->y1][(int)data->x1];
	if (data->z != 0)
		data->z = data->xyz[(int)y][(int)x] * (data->z_alt);
	if (data->z1 != 0)
		data->z1 = data->xyz[(int)data->y1][(int)data->x1] * (data->z_alt);
	x *= data->zoom;
	y *= data->zoom;
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
	isometric(&x, &y, data->z, data);
	isometric(&data->x1, &data->y1, data->z1, data);
	draw_lines(x, y, data);
}

void	draw_lines(float x, float y, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	x += data->move_x;
	y += data->move_y;
	data->x1 += data->move_x;
	data->y1 += data->move_y;
	x_step = data->x1 - x;
	y_step = data->y1 - y;
	max = MAX1(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - data->x1) || (int)(y - data->y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffff);
		x += x_step;
		y += y_step;
	}
}

void	draw_map(t_fdf *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
			{
				data->x1 = x + 1;
				data->y1 = y;
				bresenham(x, y, data);
			}
			if (y < data->height - 1)
			{
				data->x1 = x;
				data->y1 = y + 1;
				bresenham(x, y, data);
			}
			x++;
		}
		y++;
	}
}
