/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:03:26 by tpaaso            #+#    #+#             */
/*   Updated: 2022/05/04 12:26:41 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_validate_row(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit((int)str[i]) == 0 && str[i] != ' ' && str[i] != '-')
			ft_exit("error");
		if (str[i] == '-' && str[i + 1] == '-')
			ft_exit("error");
		i++;
	}
}

void	ft_validate_file(char *file)
{
	int		fd;
	char	*line;
	int		clmns;

	fd = open(file, O_RDONLY);
	if (get_next_line(fd, &line) == 0)
		ft_exit("error");
	if (line == NULL)
		ft_exit("error");
	clmns = ft_measure_width(line);
	if (clmns == 0)
		ft_exit("error");
	ft_validate_row(line);
	free(line);
	while (get_next_line(fd, &line))
	{
		if (ft_measure_width(line) != clmns)
			ft_exit("error");
		ft_validate_row(line);
		free(line);
	}
}

int	ft_measure_width(char *str)
{
	int		i;
	int		width;

	i = 0;
	width = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '-')
		{
			i++;
			if (ft_isdigit((int)str[i]) == 0)
				ft_exit("error");
		}
		if (ft_isdigit((int)str[i]) == 1)
		{
			width++;
			i++;
			while (ft_isdigit((int)str[i]) == 1)
				i++;
		}
	}
	return (width);
}

void	ft_measure_map(char *file, t_fdf *data)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (data->height == 0)
			data->width = ft_measure_width(line);
		data->height++;
		free(line);
	}
	close(fd);
}
