/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:35:51 by tpaaso            #+#    #+#             */
/*   Updated: 2022/05/04 12:25:06 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_get_values(int *xyz, char *line)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	while (tmp[i])
	{
		xyz[i] = ft_atoi(tmp[i]);
		i++;
		free(tmp[i]);
	}
	free (tmp);
}

void	ft_read_file(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	ft_measure_map(file, data);
	fd = open(file, O_RDONLY);
	if (fd == 0)
		ft_exit("error");
	i = 0;
	data->xyz = (int **)malloc(sizeof(int *) * data->height);
	while (i < data->height)
			data->xyz[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	i = 0;
	while (get_next_line(fd, &line) > 0 && i < data->height)
	{
		ft_get_values(data->xyz[i], line);
		i++;
		free(line);
	}
	close(fd);
}

int	main(int argv, char **argc)
{
	t_fdf	*data;

	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (data == NULL)
		ft_exit("error");
	data->mlx_ptr = mlx_init();
	if (argv != 2)
	{
		ft_putendl("usage: ./fdf	target_file");
		return (0);
	}
	ft_validate_file(argc[1]);
	data->zoom = 30;
	data->vert = 400;
	data->hori = 400;
	data->isox = 0.8;
	data->isoy = 0.8;
	data->color = 0xff0000;
	data->h = 3;
	ft_read_file(argc[1], data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "fdf");
	ft_draw_map(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
