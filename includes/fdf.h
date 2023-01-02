/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:36:22 by tpaaso            #+#    #+#             */
/*   Updated: 2022/04/21 12:42:32 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_fdf
{
	void		*win_ptr;
	void		*mlx_ptr;
	float		x;
	float		y;
	float		x1;
	float		y1;
	float		z;
	float		z1;
	int			height;
	int			width;
	id_t		color;
	int			**xyz;
	int			zoom;
	float		vert;
	float		hori;
	float		isox;
	float		isoy;
	float		h;
}				t_fdf;

void	ft_read_file(char *file, t_fdf *data);
void	ft_get_values(int *xyz, char *line);
void	ft_measure_map(char *file, t_fdf *data);
int		ft_measure_width(char *str);
void	ft_draw_map(t_fdf *data);
void	ft_bresenham(float x, float y, t_fdf *data);
void	ft_draw_lines(float x, float y, t_fdf *data);
void	ft_validate_row(char *str);
void	ft_validate_file(char *file);
int		deal_key(int key, t_fdf *data);
void	key_color(int key, t_fdf *data);
void	key_isometric(int key, t_fdf *data);
void	key_move(int key, t_fdf *data);

#endif