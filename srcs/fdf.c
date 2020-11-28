/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 10:44:27 by tpaaso            #+#    #+#             */
/*   Updated: 2020/10/08 17:56:50 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		measure_width(const char *str, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

int		measure_map(char *file, t_fdf *data)
{
	int		fd;
	int		height;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	height = 0;
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (i == 0)
		{
			data->width = measure_width(line, ' ');
			i++;
		}
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

void	fill_matrix(int *zyx, char *line)
{
	char	**x_axis;
	int		i;

	x_axis = ft_strsplit(line, ' ');
	i = 0;
	while (x_axis[i])
	{
		zyx[i] = ft_atoi(x_axis[i]);
		free(x_axis[i]);
		i++;
	}
	free(x_axis);
}

void	read_map(char *file, t_fdf *data)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	data->z_alt = 2;
	data->move_x = 900;
	data->move_y = 400;
	data->height = measure_map(file, data);
	data->zoom = 30;
	data->xyz = (int **)malloc(sizeof(int*) * (data->height + 1));
	while (i < data->height)
		data->xyz[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) > 0 && i < data->height)
	{
		fill_matrix(data->xyz[i], line);
		i++;
		free(line);
	}
	close(fd);
}
