/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:57:51 by tpaaso            #+#    #+#             */
/*   Updated: 2020/11/28 12:05:45 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define MAX1(a, b) (a > b ? a : b)
# define MOD(a) ((a < 0) ? -a : a)
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_fdf
{
	int			width;
	int			height;
	float		x;
	float		x1;
	float		y;
	float		y1;
	float		z;
	float		z1;
	int			**xyz;
	void		*mlx_ptr;
	void		*win_ptr;
	int			move_x;
	int			move_y;
	int			z_alt;
	int			zoom;
	float		horizontal;
	float		vertical;
}				t_fdf;

int				measure_width(const char *str, char c);

int				measure_map(char*file, t_fdf *data);

void			fill_matrix(int *zyx, char *line);

void			read_map(char *file, t_fdf *data);

int				deal_key(int key, t_fdf *data);

void			draw_map(t_fdf *data);

void			draw_lines(float x, float y, t_fdf *data);

void			isometric(float *x, float *y, int z, t_fdf *data);

int				rotate(int key, t_fdf *data);
#endif
