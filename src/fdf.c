/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:02:36 by tpaaso            #+#    #+#             */
/*   Updated: 2022/04/21 14:49:04 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_calc_max(int a, int b)
{
	int		j;
	int		k;

	j = a;
	k = b;
	if (j < 0)
		a *= -1;
	if (k < 0)
		b *= -1;
	if (a > b)
		return (a);
	return (b);
}

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->isox);
	*y = (*x + *y) * sin(data->isoy) - z;
}

void	ft_draw_lines(float x, float y, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		color;

	x_step = data->x1 - x;
	y_step = data->y1 - y;
	max = ft_calc_max(x_step, y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(x - data->x1) || (int)(y - data->y1))
	{
		color = mlx_get_color_value(data->mlx_ptr, data->color + data->z1);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + data->vert,
			y + data->hori, 0xffffff);
		if (data->z != 0)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + data->vert,
				y + data->hori, color);
		x += x_step;
		y += y_step;
	}
}

void	ft_bresenham(float x, float y, t_fdf *data)
{
	data->z = data->xyz[(int)y][(int)x] * data->h;
	data->z1 = data->xyz[(int)data->y1][(int)data->x1] * data->h;
	x *= data->zoom;
	y *= data->zoom;
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
	isometric(&x, &y, data->z, data);
	isometric(&data->x1, &data->y1, data->z1, data);
	ft_draw_lines(x, y, data);
}

void	ft_draw_map(t_fdf *data)
{
	float	x;
	float	y;

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
				ft_bresenham(x, y, data);
			}
			if (y < data->height - 1)
			{
				data->x1 = x;
				data->y1 = y + 1;
				ft_bresenham(x, y, data);
			}
			x++;
		}
		y++;
	}
}
