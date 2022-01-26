/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:38:47 by nspeedy           #+#    #+#             */
/*   Updated: 2022/01/21 13:48:30 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <stdbool.h>
# include <math.h>

typedef struct	s_rgb {
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_image {
	int		*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		ln_len;
	int		endian;
}	t_image;

typedef struct s_vector {
	double	x;
	double	y;
	double	z;
	t_rgb	rgb;
}	t_vector;

typedef struct s_map {
	int			width;
	int			height;
	int			zoom;
	int			max_z;
	int			min_z;
	t_vector	**point_data;
}	t_map;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
}	t_mlx;

void			put_pixel(t_image *img, t_vector c);
t_vector		coord_data(int x, int y, char *data);
static t_vector	*map_row(t_map *map, char **data);
t_vector		**parsemap(t_map *map, char *file);
t_image			new_image(t_mlx *mlx, int width, int height);
int				keypress(int key, void *data);
void			mlx_window(void *win);
void			draw_line(t_image *img, t_vector p1, t_vector p2);
t_rgb			hex_colour(char *data);
t_rgb			irgb(int colour);
int				rgbi(t_rgb rgb);
t_map 			*normalize(t_map *map);
void			draw(t_image *img, t_map *data, t_mlx *ptr);
t_rgb			colgrad(t_rgb c1, t_rgb c2, double percent);

#endif
